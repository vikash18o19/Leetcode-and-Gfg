class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int sum = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    //left border
                    if ((j-1) < 0 || grid[i][j-1] == 0) { sum++;}
                    //right border
                    if ((j+1) == c || grid[i][j+1] == 0) { sum++;}
                    //top border
                    if ((i-1) < 0 || grid[i-1][j] == 0) { sum++;}
                    //botton border
                    if ((i+1) == r || grid[i+1][j] == 0) { sum++;}
                }
            }
        }
        return sum;
    }
};