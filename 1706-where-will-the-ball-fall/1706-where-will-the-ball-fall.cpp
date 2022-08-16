class Solution {
public:
    int solve(vector<vector<int>>& grid,vector<vector<int>> &vis,vector<int> &ans,int i,int j,int n, int m){
        if(i==m){
            ans.push_back(j);
            return j;
        }
        if(vis[i][j]!=-1){
            return vis[i][j];
        }
        if(j==0 && grid[i][j]==-1){
            ans.push_back(-1);
            return -1;
        }
        if(j==n-1 && grid[i][j]==1){
            ans.push_back(-1);
            return -1;
        }
        if(grid[i][j]==1 && j<n-1 && grid[i][j+1]==-1){
            ans.push_back(-1);
            return -1;
        }
        if(grid[i][j]==-1 && j>0 && grid[i][j-1]==1){
            ans.push_back(-1);
            return -1;
        }
        if(grid[i][j]==1){
            return vis[i][j]=solve(grid,vis,ans,i+1,j+1,n,m);
        }
        if(grid[i][j]==-1){
            return vis[i][j]=solve(grid,vis,ans,i+1,j-1,n,m);
        }
        return 1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,-1));
        vector<int> ans;
        for(int j=0;j<n;j++){
            int x=solve(grid,vis,ans,0,j,n,m);
        }
        return ans;
    }
};