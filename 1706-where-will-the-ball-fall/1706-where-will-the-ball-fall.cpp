class Solution {
public:
    
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
                    if(grid[r][c+1]==-1){
                        break;
                    }
                    r++;
                    c++;
                }
                else{
                    if(c==0) break;
                    if(grid[r][c-1]==1){
                        break;
                    }
                    r++;
                    c--;
                    }
                }
            if(r==m) ans[j]=c;
        }
        return ans;
    }
};