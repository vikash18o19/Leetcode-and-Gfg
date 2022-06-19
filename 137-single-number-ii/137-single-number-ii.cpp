class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int  n = nums.size();
        int count =0;
        int temp;
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++){
            if(count==0){
                count++;
                temp=nums[i];
            }
            else if(count<3 && temp==nums[i] ){
                count++;
            }
            else if(count<3 && temp!=nums[i] ){
                return temp;
            }
            if(count==3){
                count=0;
            }
        }
        return temp;
    }
};