class Solution {
public:
    void solve(vector<vector<int>>& grid,vector<vector<int>> &vis,vector<int> &ans,int i,int j,int n, int m){
        if(i==m){
            ans.push_back(j);
            return;
        }
        if(vis[i][j]!=-1){
            ans.push_back(vis[i][j]);
        }
        if(j==0 && grid[i][j]==-1){
            ans.push_back(-1);
            return;
        }
        if(j==n-1 && grid[i][j]==1){
            ans.push_back(-1);
            return;
        }
        if(grid[i][j]==1 && j<n-1 && grid[i][j+1]==-1){
            ans.push_back(-1);
            return;
        }
        if(grid[i][j]==-1 && j>0 && grid[i][j-1]==1){
            ans.push_back(-1);
            return;
        }
        if(grid[i][j]==1){
            solve(grid,vis,ans,i+1,j+1,n,m);
        }
        else{
            solve(grid,vis,ans,i+1,j-1,n,m);
        }
        return;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,-1));
        vector<int> ans;
        for(int j=0;j<n;j++){
            solve(grid,vis,ans,0,j,n,m);
        }
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                cout<<i<<" "<<j<<": " <<vis[i][j]<<" | ";
            }
            cout<<"\n";
        }
        return ans;
    }
};