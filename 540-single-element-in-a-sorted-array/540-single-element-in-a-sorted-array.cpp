class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        if(n==1){
            return nums[0];
        }
        int ans =-1;
        
        while(l<=h){
            
            int mid = (l+h)/2;
            
            if(mid==0){ 
                if(nums[mid]!=nums[mid+1]){
                    ans=nums[mid];
                }
                break;
            }
            
            else if(mid==n-1){
                if(nums[mid]!=nums[mid-1]){
                    ans=nums[mid];
                }
                break;
            }
            
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                ans=nums[mid];
                break;
            }
            
            else if(nums[mid]==nums[mid+1] && mid%2==0){ 
                l=mid+1;
            }
            else if(nums[mid]!=nums[mid+1] && mid%2!=0){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};