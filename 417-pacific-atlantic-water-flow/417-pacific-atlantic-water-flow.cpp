class Solution {
public:
    
    // reverse approach intead of finding from where both oceans can be reached 
    // finding at what positions each ocean can reach.
    
    void fill(vector<vector<int>> &h,int i, int j,vector<vector<int>> &pac,int &m, int &n,int prev){
        // edge cases.
        if(i<0 || j<0 || i>=m || j>=n){
            return;
        }
        
        //if cell is already visited.
        if(pac[i][j]==1) return;
        
        
        if(h[i][j]>=prev){//if cell is explorable.
            pac[i][j]=1;
            fill(h,i-1,j,pac,m,n,h[i][j]);
            fill(h,i,j+1,pac,m,n,h[i][j]);
            fill(h,i+1,j,pac,m,n,h[i][j]);
            fill(h,i,j-1,pac,m,n,h[i][j]);
        }
        
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int m = h.size();
        int n = h[0].size();
        vector<vector<int>> pac(m,vector<int>(n,0));
        vector<vector<int>> atl(m,vector<int>(n,0));
        
        //starting from edge of both the oceans.
        for(int j =0;j<n;j++){
            if(pac[0][j]==1) continue;
            fill(h,0,j,pac,m,n,INT_MIN);
        }
        for(int i =0;i<m;i++){
            if(pac[i][0]==1) continue;
            fill(h,i,0,pac,m,n,INT_MIN);
        }
        
        for(int j =0;j<n;j++){
            if(atl[m-1][j]==1) continue;
            fill(h,m-1,j,atl,m,n,INT_MIN);
        }
        for(int i =0;i<m;i++){
            if(atl[i][n-1]==1) continue;
            fill(h,i,n-1,atl,m,n,INT_MIN);
        }
        vector<vector<int>> ans;
        vector<int>temp(2,-1);
        
        // finding where both atlantic and pacific water can reach.
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(atl[i][j]&&pac[i][j]){
                    temp[0]=i;
                    temp[1]=j;
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};