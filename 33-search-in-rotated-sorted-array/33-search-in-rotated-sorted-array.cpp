class Solution {
public:
    int bin(int l, int h, vector<int> &nums, int target){
        while(l<=h){
            int mid = l + (h-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l = 0;
        int h = n-1;
        
        if(nums[l]<=nums[h]){
            return bin(l,h,nums,target);
        }
        
        int ind;
        while(l<=h){
            int mid = l + (h-l)/2;
            //cout<<mid<<"\n";
            if(mid-1>=0){
                if(nums[mid]<nums[mid-1]){
                    ind=mid;
                    break;
                }
            }
            if(nums[mid]<nums[h]){
                h=mid-1;
            }
            else{
                
                l=mid+1;
            }
        }
        
        int ans1=-1,ans2=-1;
        if(ind-1>=0 ){
            ans1 = bin(0,ind-1,nums,target);
        }
        ans2=bin(ind,n-1,nums,target);
        
        return max(ans1,ans2);
    }
};