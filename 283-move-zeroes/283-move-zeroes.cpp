class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt =0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]==0){
                cnt++;
            }
        }
        for(int i = 0;i<cnt;i++){
            for(int j =0;j<nums.size()-1;j++){
                if(nums[j]==0){
                    swap(nums[j],nums[j+1]);
                }
            }
        }
    }
};