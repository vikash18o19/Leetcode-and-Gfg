class Solution {
public:
    bool valid(char a, char b){
        if(a=='(' && b==')'){
            return true;
        }
        else if(a=='{' &&b=='}'){
            return true;
        }
        else if(a=='[' && b==']'){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        for(int i =0;i<n;i++){
            //cout<<st.top()<<" "<<s[i]<<" ";
            if(st.empty()){
                
                st.push(s[i]);
                cout<<"stack empty pushed: "<<st.top()<<"\n";
                continue;
            }
            if(valid(st.top(),s[i])){
                st.pop();
                cout<<"got matching top in stack: "<<s[i]<<"\n";
            }
            else{
                cout<<"pushed: "<<s[i]<<"\n";
                st.push(s[i]);
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};