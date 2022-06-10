class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int pos =-1;
        for(int i =0 ;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                if(pos!=-1){
                    return false;
                }
                pos=i;
                
            }   
        }
        return pos==-1 or pos == 0 or pos==nums.size()-2 or nums[pos-1]<=nums[pos+1] or nums[pos]<=nums[pos+2];
    }
};