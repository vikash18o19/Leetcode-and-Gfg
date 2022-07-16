class Solution {
public:
    void solve(vector<int> &nums, int &ans){
        if(nums.size()==1){
            ans=nums[0];
            return;
        }
        int n  = nums.size()/2;
        vector<int> temp(n,0);
        for(int i =0;i<n;i++){
            if(i&1){
                temp[i] = max(nums[2 * i], nums[2 * i + 1]);
            }
            else{
                temp[i] = min(nums[2 * i], nums[2 * i + 1]);
            }
        }
        solve(temp,ans);
    }
    int minMaxGame(vector<int>& nums) {
        int ans;
        solve(nums,ans);
        return ans;
    }
};