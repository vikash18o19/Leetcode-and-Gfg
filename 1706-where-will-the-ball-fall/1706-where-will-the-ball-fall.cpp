class Solution {
public:
    void solve(vector<vector<int>>& grid,vector<vector<int>> &vis,vector<int> &ans,int i,int j,int n, int m){
        if(i==m){
            ans.push_back(j);
            vis[i][j]=j;
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
            if(vis[i+1][j+1]!=-1){
                vis[i][j]=vis[i+1][j+1];
            }
        }
        else{
            solve(grid,vis,ans,i+1,j-1,n,m);
            if(vis[i+1][j-1]!=-1 ){
                vis[i][j]=vis[i+1][j-1];
            }
        }
        return;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> ans(n,-1);
        for(int j=0;j<n;j++){
            int r =0;
            int c =j;
            while(r<m){
                if(grid[r][c]==1){
                    if(c==n-1) break;
                    else{
                        if(grid[r][c+1]==-1){
                            break;
                        }
                        else{
                            r++;
                            c++;
                        }
                    }
                }
                else{
                    if(c==0) break;
                    else{
                        if(grid[r][c-1]==1){
                            break;
                        }
                        else{
                            r++;
                            c--;
                        }
                    }
                }
            }
            if(r==m) ans[j]=c;
        }
        return ans;
    }
};