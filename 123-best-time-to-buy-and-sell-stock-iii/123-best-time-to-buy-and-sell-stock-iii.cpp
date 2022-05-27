class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // for(int i=0;i<=2;i++){
        //     dp[n][0][i]=dp[n][1][i]=0;
        // }
        // for(int i=0;i<=n;i++){
        //     dp[i][0][0]=dp[i][1][0]=0;
        // }
        //dp[n][0]=dp[n][1]=0;
        for(int ind = n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int count=1;count<=2;count++){
                int profit =0;
                if(buy==1){
                    int take = (-1*p[ind]) + dp[ind+1][0][count];   
                    int not_take = dp[ind+1][1][count];
                    profit =  max(take,not_take);
                }
                else{
                    int sell = p[ind] + dp[ind+1][1][count-1];   
                    int not_sell = dp[ind+1][0][count];
                    profit = max(sell,not_sell);
                }
                 dp[ind][buy][count]= profit;
            }
            }
        }
        
        int ans = dp[0][1][2];
        return ans;
    }
};