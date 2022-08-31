class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size();
        int i=0;
        int flag=0;
        queue<string> d;
        string temp ="";
        while(i<n){
            if(title[i]==' '){
                //cout<<temp<<" ";
                d.push(temp);
                temp.clear();
            }
            else{
                char a = tolower(title[i]);
                
                temp+=a;
            }
            i++; 
        }
        cout<<d.size();
        d.push(temp);
        temp.clear();
        int k=0;
        while(!d.empty()){
            //cout<<k++<<" ";
            if(d.front().size()==1 || d.front().size()==2){
                temp+=d.front();
                temp+=" ";
            }
            else{
                string s=d.front();
                char a = toupper(s[0]);
                s[0]=a;
                //cout<<s<<" | ";
                temp+=s;
                temp+=" ";
            }
            d.pop();
        }
        temp.pop_back();
        return temp;
    }
};