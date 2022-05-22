class Solution {
public:
    int ans(vector<int> &nums){
        vector<int> dp(nums.size(),-1);
        
        dp[0]=nums[0];
        
        for(int i=1;i<nums.size();i++){
            int take = nums[i];
            if(i>1) take+= dp[i-2];
            int not_take = dp[i-1];
            dp[i]=max(take,not_take);
        }
        return dp[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> first;
        vector<int> second;
        
        for(int i=0;i<nums.size();i++){
            if(i!=0) first.push_back(nums[i]);
            if(i!=nums.size()-1) second.push_back(nums[i]);
            
        }
        int a = ans(first);
        //cout<<a<<" ";
        int b = ans(second);
        //cout<<b<<" ";
        return max(a,b);
    }
};