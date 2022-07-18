class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        if(n==1){
            return 0;
        }
        while(l<h){
            //cout<<"l: "<<l<<" h: "<<h<<"\n";
            int mid = l+(h-l)/2;
            if(nums[mid]>nums[mid+1]){
                h=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};