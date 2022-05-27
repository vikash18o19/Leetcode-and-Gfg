class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        
        for(int ind = n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                if(buy==1){
                    dp[ind][buy]=max((-1*p[ind])+dp[ind+1][0],dp[ind+1][1]);
                }
                else{
                    dp[ind][buy]=max(p[ind]+dp[ind+2][1],dp[ind+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};