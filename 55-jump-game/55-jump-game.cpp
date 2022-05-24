class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max=nums[0];
        int i=1;
        while(i<=max && i<nums.size()){
            if(nums[i]+i>max)
                max=nums[i]+i;
            i++;
            
        }
        if(nums.size()-1<=max){
            return true;
        }
        else
            return false;
    }
};