class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        
        stack<char> st_s;
        stack<char> st_t;
        
        for(int i =0;i<n1;i++){
            if(s[i]=='#'){
                if(!st_s.empty())
                    st_s.pop();
            }
            else{
                st_s.push(s[i]);
            }
        }
        for(int i =0;i<n2;i++){
            if(t[i]=='#'){
                if(!st_t.empty())
                    st_t.pop();
            }
            else{
                st_t.push(t[i]);
            }
        }
        
        while(!st_s.empty() && !st_t.empty()){
            cout<<st_s.size()<<" "<<st_t.size()<<"\n";
            if(st_s.top()==st_t.top()){
                //cout<<st_s.top()<<" "<<st_t.top()<<"\n";
                st_s.pop(); st_t.pop();
            }
            else{
                return false;
            }
                        //cout<<st_s.size()<<" "<<st_t.size()<<"\n";

        }
        if(st_s.empty() && st_t.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};