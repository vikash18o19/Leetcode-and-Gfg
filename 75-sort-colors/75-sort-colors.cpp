class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            for(int j  =1;j<n;j++){
                if(nums[j]<nums[j-1]){
                    swap(nums[j],nums[j-1]);
                }
            }
        }
        
    }
};