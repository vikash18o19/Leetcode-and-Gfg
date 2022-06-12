class Solution {
public:
    int solve(int ind, vector<int> &arr, int &k,vector<int> &dp){
        if(ind == arr.size()){
            return 0;
        }
        
        if(dp[ind]!=-1){
            return dp[ind];
        }
        
        int maxAns=INT_MIN;
        int maxi = INT_MIN;
        int n=0;
        int sum;
        int s = arr.size();
        for(int j = ind;j<min(ind+k,s);j++){
            n++;
            maxi=max(maxi,arr[j]);
            sum = n*maxi + solve(j+1,arr,k,dp);
            maxAns= max(maxAns,sum);
        }
        return dp[ind]=maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return solve(0,arr,k,dp);
    }
};