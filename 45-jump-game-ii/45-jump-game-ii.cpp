class Solution {
public:
    int solve(int ind,vector<int> &nums,vector<int> &dp){
        if(ind>=nums.size()-1){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int mini = 10e6;
        for(int i =1;i<=nums[ind];i++){
            mini = min(mini,solve(ind+i,nums,dp));
        }
        return dp[ind]= 1+mini;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return solve(0,nums,dp);
    }
};