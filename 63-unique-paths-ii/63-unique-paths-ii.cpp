class Solution {
public:
    int solve(int r,int c,vector<vector<int>> &dp,
              vector<vector<int>> &g){
        
        if(r<0 || c<0){
            return 0;
        }
        if(r==0 && c==0){
            if(g[r][c]!=1)
                return 1;
            else
                return 0;
        }
        if(g[r][c]==1){
            return 0;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int right = solve(r,c-1,dp,g);
        int down = solve(r-1,c,dp,g);
        
        return dp[r][c]=right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &g) {
        int m=g.size();
        int n=g[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp,g);
    }
};