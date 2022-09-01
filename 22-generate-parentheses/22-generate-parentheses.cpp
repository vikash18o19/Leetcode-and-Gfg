class Solution {
public:
    void solve(int l, int r, string temp, vector<string> &ans){
        //cout<<l<<" "<<r<<"\n";
        if(l==0 && r==0){
            ans.push_back(temp);
            return;
        }
        
        if(r>l && r>0){
            solve(l,r-1,temp+")",ans);
        }
        if(r>0 && l>0){
            solve(l-1,r,temp+"(",ans);
        }
        return;
        
    }
    vector<string> generateParenthesis(int n) {
        int l = n;
        int r = n;
        string temp = "";
        vector<string> ans;
        solve(l,r,temp,ans);
        return ans;
    }
};