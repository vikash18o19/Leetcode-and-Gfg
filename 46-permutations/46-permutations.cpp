class Solution {
public:
    void solve(int ind, vector<vector<int>> &ans, 
               vector<int> subset ,vector<int> nums){
        if(nums.size()==0){
            ans.push_back(subset);
            return;
        }
        
        if(ind<nums.size()){
            solve(ind+1,ans,subset,nums);
            subset.push_back(nums[ind]);
            nums.erase(nums.begin()+ind);
            solve(0,ans,subset,nums);
        }
        else
            return;        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> subset;
        solve(0,ans,subset,nums);
        return ans;
    }
};