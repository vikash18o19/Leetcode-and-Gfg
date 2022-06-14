class Solution {
public:
    int solve(int r,int c,vector<vector<int>> &dp){
        if(r<0 || c<0){
            return 0;
        }
        if(r==0 && c==0){
            return 1;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int right = solve(r,c-1,dp);
        int down = solve(r-1,c,dp);
        
        return dp[r][c]=right + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector(n,-1));
        return solve(m-1,n-1,dp);
    }
};