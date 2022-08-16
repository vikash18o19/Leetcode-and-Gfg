class Solution {
public:
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n, -1);
        for(int i = 0;i<n;i++) {
            int r = 0, c = i;
            while(r < m) {
                if(grid[r][c] == 1) {
                    if(c == n-1) break; //it's a wall
                    if(c < n-1 && grid[r][c+1] == -1) break; // it's V shaped
                    r++;c++;
                }
                else {
                    if (c==0) break;
                    if(c > 0 && grid[r][c-1] == 1) break;
                    r++;c--;
                }
            }
            if(r==m) ans[i] = c; // we have passed through all columns 
        }
        
        return ans;
    }
};