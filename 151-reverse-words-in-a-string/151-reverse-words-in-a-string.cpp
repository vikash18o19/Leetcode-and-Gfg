class Solution {
public:
    string reverseWords(string s) {
        string res;
        stack<string> st;
        s+='$';
        string temp="";
        int n = s.size();
        int flag = 0;
        for(int  i =0;i<n;i++){
            if(s[i]=='$')break;
            if(flag==0 && s[i]==' '){
                continue;
            }
            else if(flag==0 &&s[i]!=' '){
                flag =1;
                while(s[i]!=' ' && s[i]!='$'){
                    temp+=s[i];
                    i++;
                }
                st.push(temp);
                temp.clear();
            }
            else if(flag==1 && s[i]!=' '){
                while(s[i]!=' ' && s[i]!='$'){
                    temp+=s[i];
                    i++;
                }
                st.push(temp);
                temp.clear();
            }
        }
        
        if(!st.empty()){
            res=res+st.top();
            st.pop();
            while(!st.empty()){
                res+=' ';
                res=res+st.top();
                st.pop();
            }
        }
        return res;
    }
};