class Solution {
public:
    string convertToTitle(int columnNumber) {
        int x = columnNumber;
        stack<char> st;
        while(x){
            char temp = 'A'+(x-1)%26;
            st.push(temp);
            x=(x-1)/26;
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};