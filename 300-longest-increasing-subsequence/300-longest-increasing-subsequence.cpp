class Solution {
public:
//     int solve(int ind, int prev, vector<int> &n, vector<vector<int>> &dp){
//         if(ind == n.size()) return 0;
//         if(dp[ind][prev+1]!=-1){
//             return dp[ind][prev+1];
//         }
//         int take = INT_MIN;
//         if(prev==-1 || n[prev]<n[ind]){
//                 take = 1 + solve(ind+1,ind,n,dp);
//             //cout<<n[ind-1]<<" ";
//         }    
        
//         int not_take = solve(ind+1,prev,n,dp);
//         return dp[ind][prev+1]=max(take,not_take);
        
//     }
    int lengthOfLIS(vector<int>& n) {
        vector<vector<int>> dp(n.size()+1,vector<int>(n.size()+1,0));
        for(int ind =n.size()-1;ind>=0;ind--){
            for(int prev = ind-1;prev>=-1;prev--){
                int take = INT_MIN;
                if(prev==-1 || n[prev]<n[ind]){
                        take = 1 + dp[ind+1][ind+1];
                    //cout<<n[ind-1]<<" ";
                }    

                int not_take = dp[ind+1][prev+1];
                dp[ind][prev+1]=max(take,not_take);
            }
        }
        return dp[0][0];
    }
};