class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ge  (m,vector<int>(n,0));
        vector<vector<int>> gw  (m,vector<int>(n,0));
        vector<vector<int>> gn  (m,vector<int>(n,0));
        vector<vector<int>> gs  (m,vector<int>(n,0));
        
        for(int i =0;i<m;i++){
            for(int j =1;j<n;j++){
                gw[i][j]=max(grid[i][j-1],gw[i][j-1]);
                ge[i][n-j-1]=max(grid[i][n-j],ge[i][n-j]);
                gn[j][i]=max(grid[j-1][i],gn[j-1][i]);
                gs[m-j-1][i]=max(grid[m-j][i],gs[m-j][i]);
            }
        }
        
        int ans = 0;
        
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                int h = min(max(ge[i][j],gw[i][j]),
                            max(gn[i][j],gs[i][j]));
                int diff =  h-grid[i][j];
                ans+=max(0,diff);
            }
        }

        return ans;
    }
};