class Solution {
public:
    
    int solve(int e,int f,vector<vector<int>> &dp){
        // Base case(if there are 0 floors or 1 floor then minimum attempts can be floor size)
        if(f==0 || f==1)
            return f;
        // if there is only 1 given egg then the worst case is that it will break from top
        if(e==1)
            return f;
        // Memoization usage if element found in dp matrix return that
        if(dp[e][f]!=-1)
            return dp[e][f];
        // Declaring variables for binary search
        int mini=INT_MAX,l=1,r=f;
        // Binary search algo to optimize the code as it is giving TLE without using it
        while(l<=r){
            int mid=l+(r-l)/2;
            int left=solve(e-1,mid-1,dp); // passed e-1 considering egg is breaked
            int right=solve(e,f-mid,dp);// passed e considering egg is not breaked
            int temp=1+max(left,right); // finding max bcz calculating in worst case
            if(left<right)
                l=mid+1;
            else
                r=mid-1;
            mini=min(temp,mini);// Finding minimum number of attempts possible
        }
        return dp[e][f]=mini;
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1)); // initialising a 2-D dp matrix with -1 values
        return solve(k,n,dp);
    }
};