class Solution {
public:
    void swap(int a, int b, vector<int> &nums){
        int temp = nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
    }
    void solve(int ind, vector<vector<int>> &ans, 
               vector<int> &nums){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i =ind; i<nums.size();i++){
            //cout<<nums[ind]<<"  "<<nums[i]<<"\n";
            swap(ind,i,nums);
            //cout<<nums[ind]<<"  "<<nums[i]<<"\n";
            solve(ind+1,ans,nums);
            swap(ind,i,nums);
        }
        return;        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
       // vector<int> subset;
        solve(0,ans,nums);
        return ans;
    }
};