class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        int n  =nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end(),greater<int>());
        int l =0;
        for(int i =0;i<n;i++){
            if(nums[l]-nums[i]>k){
                ans++;
                l=i;
            }
        }
        return ans+1;
    }
};