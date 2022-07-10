class Solution {
public:
    int solve(int i, int j, string w1, string w2,
             vector<vector<int>> &dp){
        
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        
        if(w1[i]==w2[j]){
            return dp[i][j]=solve(i-1,j-1,w1,w2,dp);
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int del = 1 + solve(i-1,j,w1,w2,dp);
        int rep = 1 + solve(i-1,j-1,w1,w2,dp);
        int ins = 1 + solve(i,j-1,w1,w2,dp);
        
        return dp[i][j]=min(del,min(rep,ins));
        
    }
    int minDistance(string w1, string w2) {
        int n1 = w1.size();
        int n2 = w2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return solve(n1-1,n2-1,w1,w2,dp);
    }
};