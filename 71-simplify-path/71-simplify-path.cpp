class Solution {
public:
    string simplifyPath(string path) {
        int i =0;
        deque<string> st;
        while(i<path.size()){
            
            string temp="";
            if(path[i]=='/'){
                i++;
                while(i<path.size() && path[i]!='/'){
                    temp+=path[i];
                    i++;
                }
                i--;
            }
            if(temp==""){
                i++;
                continue;
            }
            else if(temp==".."){
                if(!st.empty())
                    st.pop_back();
                i++;
                continue;
            }
            else if(temp=="."){
                i++;
                continue;
            }
            else{
                //cout<<"pushed"<<"\n";
                st.push_back(temp);
            }
            i++;
            
        }
        string ans;
        if(!st.empty())
        while(!st.empty()){
            ans+='/'+st.front();
            st.pop_front();
        }
        else{
            ans+='/';
        }
        return ans;
    }
};