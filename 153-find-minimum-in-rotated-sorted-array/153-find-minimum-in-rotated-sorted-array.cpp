class Solution {
public:
    int findMin(vector<int>& nums) {
        int n  = nums.size();
        if(nums[0]<=nums[n-1]) return nums[0];
        
        int l = 0;
        int h = n-1;
        
        while(l<=h){
            int mid = l+(h-l)/2;
            //cout<<mid;
            if(mid-1>=0 && nums[mid]<nums[mid-1]){
                return nums[mid];
            }
            if(mid==0){
                if(nums[mid]>nums[n-1]){
                    l=mid+1;
                }
            }
            else if(nums[0]>nums[mid]){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return nums[0];
    }
};