class Solution {
public:
    
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(p.size()+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int ind = n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit =0;
                if(buy==1){
                    int take = (-1*p[ind]) + dp[ind+1][0];   
                    int not_take = dp[ind+1][1];
                    profit =  max(take,not_take);
                }
                else{
                    int sell = p[ind] + dp[ind+1][1];   
                    int not_sell = dp[ind+1][0];
                    profit = max(sell,not_sell);
                }
                 dp[ind][buy]= profit;
            }
        }
        
        int ans = dp[0][1];
        return ans;
    }
};