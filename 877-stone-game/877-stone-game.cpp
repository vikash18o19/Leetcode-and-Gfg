class Solution {
public:
    int solve(int l, int r, vector<int> &p, vector<vector<int>> &dp){
        if(l>r) return 0;
        
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        return dp[l][r]=max(p[l]-solve(l+1,r,p,dp),p[r]-solve(l,r-1,p,dp));
        
    }
    bool stoneGame(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,p,dp)>0;
    }
};