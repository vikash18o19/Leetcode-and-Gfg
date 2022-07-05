class Solution {
public:
    void solve(queue<pair<int,int>> q, vector<vector<int>>& grid, int &count){
        if(q.empty()){
            return;
        }
        queue<pair<int,int>> cur_q;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            if(i-1>=0){
                if(grid[i-1][j]==1){
                    cur_q.push({i-1,j});
                    grid[i-1][j]=2;
                }
            }
            if(j-1>=0){
                if(grid[i][j-1]==1){
                    cur_q.push({i,j-1});
                    grid[i][j-1]=2;
                }
            }
            if(i+1<grid.size()){
                if(grid[i+1][j]==1){
                    cur_q.push({i+1,j});
                    grid[i+1][j]=2;
                }
            }
            if(j+1<grid[0].size()){
                if(grid[i][j+1]==1){
                    cur_q.push({i,j+1});
                    grid[i][j+1]=2;
                }
            }
            q.pop();    
        }
        count++;
        solve(cur_q,grid,count);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int flag0 =0;
        queue<pair<int,int>> q;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    flag0=1;
                }
                if(grid[i][j]==1){
                    flag0=1;
                }
            }
        }
        if(flag0==0){
            return 0;
        }
        int count =0;
        solve(q,grid,count);
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                //cout<<grid[i][j]<<" ";
                if(grid[i][j]==1){
                    
                    return -1;
                }
            }
            //cout<<"\n";
        }
        return count-1;
    }
};