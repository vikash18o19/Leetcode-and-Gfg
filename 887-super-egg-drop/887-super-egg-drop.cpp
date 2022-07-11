class Solution {
public:
    int solve(int k, int n, vector<vector<int>> &dp){
        
        if(n==1 || n==0){
            return n;
        }
        
        if(k==1){
            return n;
        }
        
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        
         int mn = INT_MAX;
        int l = 1;
        int r = n;
        while(l<=r){
            int mid = l+ (r-l) /2;
            int left = solve(k-1,mid-1,dp);
            int right = solve(k,n-mid,dp);
            int temp = 1 + max(left,right);
            if (left<right)  
                l=mid+1;
            else
                r=mid-1;
            mn = min(mn,temp);
   
        }
        return dp[n][k]=mn;
    }
    int superEggDrop(int k, int n) {
         vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(k,n,dp);
    }
};