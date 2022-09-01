class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int n  =ops.size();
        for(int i  =0;i<n;i++){
            if(ops[i]=="+"){
                int s1 = st.top();
                st.pop();
                int s2 = st.top();
                int s = s1+s2;
                st.push(s1);st.push(s);
            }
            else if(ops[i]=="D"){
                st.push(st.top()*2);
            }
            else if(ops[i]=="C"){
                st.pop();
            }
            else{
                st.push(stoi(ops[i]));
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};