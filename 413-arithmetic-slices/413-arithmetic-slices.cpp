class Solution {
public:
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int ans=0;
        //sort(nums.begin(),nums.end());
        for(int i=2;i<nums.size();i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                if(dp[i-1]>0){
                    dp[i]=dp[i-1]+1;
                    ans+=dp[i];
                }
                else{
                    dp[i]=1;
                    ans+=dp[i];
                }
            }
            
        }
        return ans;
    }
};