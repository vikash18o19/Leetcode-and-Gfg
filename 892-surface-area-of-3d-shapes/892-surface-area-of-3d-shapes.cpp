class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int area = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]!=0){
                    area+=2;
                }
                if(i-1>=0){
                    int temp = grid[i][j]-grid[i-1][j];
                    if(temp>0){
                        area+=temp;
                    }
                }
                else{
                    area+=grid[i][j];
                }
                if(i+1<m){
                    int temp = grid[i][j]-grid[i+1][j];
                    if(temp>0){
                        area+=temp;
                    }
                }
                else{
                    area+=grid[i][j];
                }
                if(j-1>=0){
                    int temp = grid[i][j]-grid[i][j-1];
                    if(temp>0){
                        area+=temp;
                    }
                }
                else{
                    area+=grid[i][j];
                }
                if(j+1<n){
                    int temp = grid[i][j]-grid[i][j+1];
                    if(temp>0){
                        area+=temp;
                    }
                }
                else{
                    area+=grid[i][j];
                }
            }
        }
        return area;
    }
};