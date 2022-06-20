class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int ans=-1;
        int flag = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==1){
                flag=1;
            }
            if(nums[i]>n || nums[i]<1){
                nums[i]=1;
            }
        }
        // for(int i = 0;i<n;i++){
        //     cout<<nums[i]<<" "; 
        // }
        if(flag==0){
            return 1;
        }
        for(int i =0;i<n;i++){
            if(nums[abs(nums[i])-1]>0){
                nums[abs(nums[i])-1]=-1*nums[abs(nums[i])-1];
            }
        }
        cout<<"\n";
        // for(int i = 0;i<n;i++){
        //     cout<<nums[i]<<" "; 
        // }
        //cout<<nums[0]<<" "<<ans;
        
        for(int i =0;i<n;i++){
            if(nums[i]>0){
                ans=i+1;
                break;
            }
        }
        if(ans==-1){
            ans=n+1;
        }
        return ans;
    }
};