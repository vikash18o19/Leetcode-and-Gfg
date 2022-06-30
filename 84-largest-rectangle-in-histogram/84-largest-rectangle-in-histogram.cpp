class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        stack<int> st;
        int ls[n];
        int rs[n];
        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()]>=h[i]){
                st.pop();
            }
            if(st.empty()){
                ls[i]=0;
            }
            else{
                ls[i]=st.top()+1;
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && h[st.top()]>=h[i]){
                st.pop();
            }
            if(st.empty()){
                
                rs[i]=n-1;
                //cout<<rs[i]<<" ";
            }
            else{
                rs[i]=st.top()-1;
                //cout<<rs[i]<<" ";
            }
            st.push(i);
        }
        int ans= INT_MIN;
        
        for(int i =0;i<n;i++){
            ans= max(ans,h[i]*(rs[i]-ls[i]+1));
        }
        return ans;
    }
};