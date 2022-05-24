class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int tot = 0;
        int flag=0;
        for(int i= 0;i<nums.size();i++){
            if(nums[i]>=0){
                flag=1;
            }
            tot+=nums[i];
            //if(nums[i]>max1){
            //    max1 = nums[i];
            //}
        }
        if(flag==0){
            int max1=INT_MIN;
            for(int i= 0;i<nums.size();i++){
                if(nums[i]>max1){
                    max1 = nums[i];
                }
        }
            return max1;
        }
        
        int sum =0;
        int maxi = (-1*nums[0]);
        for(int i=0;i<nums.size();i++){
            sum+=(-1*nums[i]);
            if(sum<0){
                sum=0;
            }
            if(maxi < sum ){
                maxi = sum;
            }
            //cout<<"rev: "<<sum<<"  "<<maxi<<"\n";
        }
        int ans = tot-(-1*maxi);
        sum =0;
        maxi = nums[0];
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0){
                sum=0;
            }
            if(maxi < sum ){
                maxi = sum;
            }
            //cout<<""<<sum<<"  "<<maxi<<"\n";
        }
        return max(maxi,ans);
    }
};