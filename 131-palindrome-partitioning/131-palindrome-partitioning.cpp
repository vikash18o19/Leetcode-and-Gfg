class Solution {
public:
    string sub(int l,int h, string s){
        string ans="";
        while(l<=h){
            ans+=s[l];
            l++;
        }
        
        return ans;
    }
    bool palin(int l, int h, string &s){
        while(l<h){
            if(s[l]!=s[h]){
                return false;
            }
            l++;
            h--;
        }
        return true;
    }
    void solve(string &s, int ind, int n, vector<string> ans, 
               vector<vector<string>> &out){
        if(ind == n){
            out.push_back(ans);
            return;
        }
        
        for(int i = ind; i<n; i++){
            if(palin(ind,i,s)){
                ans.push_back(sub(ind,i,s));
                solve(s,i+1,n,ans,out);
                ans.erase(ans.end()-1);
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> out;
        vector<string> ans;
        int n = s.size();
        solve(s,0,n,ans,out);
        //cout<<"test: "<<s.substr(1,1+1);
        return out;
    }
};