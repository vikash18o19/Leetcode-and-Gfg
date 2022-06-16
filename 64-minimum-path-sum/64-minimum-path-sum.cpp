class Solution {
public:
    int solve(int i, int j,vector<vector<int>>& grid, vector<vector<int>>&dp){
        if(i==0&&j==0)return grid[i][j];
        if(i<0||j<0)return 10e5;
        if(dp[i][j]!=-1)return dp[i][j];
        int left = grid[i][j]+solve(i-1,j,grid,dp);
        int up = grid[i][j]+solve(i,j-1,grid,dp);
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans = solve(m-1,n-1,grid,dp);
        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        return ans;
    }
};