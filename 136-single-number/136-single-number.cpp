class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int temp;
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(count==0){
                temp=nums[i];
                count++;
            }
            else if(count<2){
                if(temp==nums[i]) count++;
                else return temp;
            }
            if(count==2) count=0;
        }
        if(count==1)return nums[n-1];
        return temp;
    }
};