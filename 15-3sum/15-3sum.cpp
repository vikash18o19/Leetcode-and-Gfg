class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n =nums.size();
        vector<vector<int>> res;
        if(n<3){
            return res;
        }
        for(int i = 0;i<n;i++){
            if(i>0){
                if(nums[i]==nums[i-1]){
                    continue;
                }
            }
            int lo = i+1;
            int hi = n-1;
            int sum = 0 - nums[i];
            while(lo<hi){
                if(nums[lo]+nums[hi]==sum){
                    res.push_back({nums[i],nums[lo],nums[hi]});
                    while(lo<hi && nums[lo]==nums[lo+1])lo++;
                    while(lo<hi && nums[hi]==nums[hi-1])hi--;
                    lo++;
                    hi--;
                }
                else{
                    if(nums[lo]+nums[hi]>sum){
                        hi--;
                    }
                    else{
                        lo++;
                    }
                }
            }
            
        }
        return res;
    }
};