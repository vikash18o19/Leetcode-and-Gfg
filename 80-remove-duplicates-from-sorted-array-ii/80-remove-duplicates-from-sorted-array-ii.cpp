class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        if(n ==1) return 1;
        
        int ind=1;
        int count=1;
        for(int i = 1;i<n;i++){
            if(nums[i-1]!=nums[i]){
                nums[ind]=nums[i];
                ind++;
                count =1;
            }
            else if(nums[i-1]==nums[i] && count<2){
                nums[ind]=nums[i];
                ind++;
                count++;
            }
        }
        return ind;
    }
};