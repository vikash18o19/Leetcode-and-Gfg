class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         vector<int>ans;
        int ans1=-1;
        int ans2=-1;
        int l=0;
        int h=nums.size()-1;
        
        int mid;
        
        while(l<=h){
            mid=(h-l)/2 +l;
            if(nums[mid]==target){
                ans1=mid;
                h=mid-1;
            }
            else if(nums[mid]<target)l=mid+1;
            else if(nums[mid]>target)h=mid-1;
        }
        l=0;
        h=nums.size()-1;
        while(l<=h){
            mid=(h-l)/2 +l;
            if(nums[mid]==target){
                ans2=mid;
                l=mid+1;
                }
            
            else if(nums[mid]<target)l=mid+1;
            else if(nums[mid]>target)h=mid-1;
        }
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};