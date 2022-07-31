class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row(m,0);
        vector<int> col(n,0);
        
        
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                row[i]=max(row[i],grid[i][j]);
                col[i]=max(col[i],grid[j][i]);
            }
        }
        
        int ans = 0;
        
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                int h = min(row[i],col[j]);
                int diff =  h-grid[i][j];
                ans+=max(0,diff);
            }
        }

        return ans;
    }
};