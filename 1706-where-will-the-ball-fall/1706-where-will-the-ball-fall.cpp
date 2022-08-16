class Solution {
public:
    void solve(int &m, int &n, vector<vector<int>> &grid,int i, int j, vector<int> &ans, vector<vector<int>> &dp){
        if(i==m){
            ans.push_back(j);
            return;
        }
        if(j<0 || j>=n){
            ans.push_back(-1);
            return;
        }
        if((j==0 && grid[i][j]==-1) || (j==n-1 && grid[i][j]==1)){
            ans.push_back(-1);
            return;
        }
        if((j>=0 && j<n)&&
           ((grid[i][j]==1 && grid[i][j+1]==-1)||(grid[i][j]==-1 && grid[i][j-1]==1))){
            ans.push_back(-1);
            return;
        }
        if(dp[i][j]!=-1){
            ans.push_back(dp[i][j]);
            return;
        }
        if(grid[i][j]==-1){
            solve(m,n,grid,i+1,j-1,ans,dp);
        }
        else{
            solve(m,n,grid,i+1,j+1,ans,dp);
        }
        return;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        vector<int> ans;
        vector<vector<int>> dp(grid.size(),vector<int>(n,-1));
        for(int i =0;i<n;i++){
            solve(m,n,grid, 0, i, ans,dp);
        }
        return ans;
    }
};