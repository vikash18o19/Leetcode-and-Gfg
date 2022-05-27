class Solution {
public:
    bool check(int i , int j, int n, int m){
        if(i<0 || j<0 || i>=n||j>=m){
            return false;
        }
        else return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        
        queue<pair<int,int>> q;
        
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            
            if(check(i-1,j,n,m) && ans[i-1][j]==-1){
                q.push({i-1,j});
                ans[i-1][j]=1+ans[i][j];
            }
            if(check(i+1,j,n,m) && ans[i+1][j]==-1){
                q.push({i+1,j});
                ans[i+1][j]=1+ans[i][j];
            }
            if(check(i,j-1,n,m) && ans[i][j-1]==-1){
                q.push({i,j-1});
                ans[i][j-1]=1+ans[i][j];
            }
            if(check(i,j+1,n,m) && ans[i][j+1]==-1){
                q.push({i,j+1});
                ans[i][j+1]=1+ans[i][j];
            }
            q.pop();
        }
        return ans;
    }
};