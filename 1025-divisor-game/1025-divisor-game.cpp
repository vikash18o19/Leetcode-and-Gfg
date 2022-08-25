class Solution {
public:
    int solve(int n,int turn,vector<vector<int>> &dp){
        if(n==1){
            return 0;  
        }
        if(dp[n][turn]!=-1){
            return dp[n][turn];
        }
        for(int x=1;x<n;x++){
            if(n%x==0){
                int res = solve(n-x,1-turn,dp);
                if(res==0){
                    return dp[n][turn]=1;
                }
                
            }
        }
        return dp[n][turn]=0;
    }
    bool divisorGame(int n) {
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(n,0,dp);
    }
};