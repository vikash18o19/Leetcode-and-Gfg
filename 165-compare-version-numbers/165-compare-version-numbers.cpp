class Solution {
public:
    void solve(string &version, vector<int> &v){
        int n = version.size();
        string temp="";
        for(int i = 0;i<n;i++){
            //cout<<version[i];
            while(i<n && version[i]!='.'){
                
                temp+=version[i];
                i++;
            }
            //cout<<temp<<"\n";
            v.push_back(stoi(temp));
            temp.clear();
        }
        //stoi();  
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        solve(version1,v1);
        vector<int> v2;
        solve(version2,v2);
        int n1 = v1.size();
        int n2 = v2.size();
        int n =abs(n1-n2);
        for(int i =0;i<n;i++){
            if(n1<n2){
                v1.push_back(0);
            }
            else{
                v2.push_back(0);
            }
        }
        //cout<<n;
        for(int i =0;i<max(n1,n2);i++){
            //cout<<v1[i]<<" "<<v2[i]<<"\n";
            if(v1[i]<v2[i]){
                return -1;
            }
            else if(v1[i]>v2[i]){
                return 1;
            }
        }
        return 0;
    }
};