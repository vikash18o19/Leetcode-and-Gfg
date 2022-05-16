class Solution {
public:
    int collect(vector<int> &nums,int ind, vector<int> &dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int take = nums[ind] + collect(nums,ind+2,dp);
        int not_take = collect(nums,ind+1,dp);
        
        return(dp[ind] = max(take,not_take));
         
    }
    int rob(vector<int>& nums) {
        int ans;
        vector<int> dp(nums.size(),-1);
        ans = collect(nums,0,dp);
        return ans;
        
        
    }
};