class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        if(n==1){
            return 0;
        }
        while(l<=h){
            //cout<<"l: "<<l<<" h: "<<h<<"\n";
            int mid = l+(h-l)/2;
            //cout<<mid<<" \n";
            if(mid==0 && nums[mid+1]<nums[mid]){
                return mid;
            }
            if(mid==0 && nums[mid+1]>nums[mid]){
                l=mid+1;
                continue;
            }
            if(mid==n-1 && nums[mid-1]<nums[mid]){
                return mid;
            }
            if(mid==n-1 && nums[mid-1]>nums[mid]){
                h=mid-1;
                continue;
            }
            if(nums[mid-1]<nums[mid] && nums[mid+1]<nums[mid]){
                return mid;
            }
            else if(nums[mid]<nums[mid+1] && nums[mid-1]<nums[mid]){
                l=mid+1;
            }
            else if(nums[mid]>nums[mid+1] && nums[mid-1]>nums[mid]){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }
};