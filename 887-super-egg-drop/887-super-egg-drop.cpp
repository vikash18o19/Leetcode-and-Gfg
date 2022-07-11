class Solution {
public:
    int solve(int k, int n, vector<vector<int>> &dp){
        
        if(n==1 || n==0){
            return n;
        }
        
        if(k==1){
            return n;
        }
        
        if(dp[k][n]!=-1){
            return dp[k][n];
        }
        
        int ans = INT_MAX;
        int l =1;
        int h =n;
        while(l<=h){
            int mid = (l+h)/2;
            int broke = solve(k-1,mid-1,dp);
            int not_broke=solve(k,n-mid,dp);
            if(broke<not_broke){
                l = mid+1;
            }
            else{
                h=mid-1;
            }
            int mx = 1+max(broke,not_broke);
            ans = min(ans,mx);
        }
        return dp[k][n]=ans;
    }
    int superEggDrop(int k, int n) {
         vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        //cout<<k<<" "<<n<<"\n";
        return solve(k,n,dp);
    }
};