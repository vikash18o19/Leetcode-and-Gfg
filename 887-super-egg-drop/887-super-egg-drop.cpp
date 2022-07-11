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
        return dp[k][n] = mn;
    }
    int superEggDrop(int k, int n) {
         vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        //cout<<k<<" "<<n<<"\n";
        return solve(k,n,dp);
    }
};