class Solution {
public:
    void solve(int ind, vector<int> &nums, vector<int> vec,
              vector<vector<int>> &ans){
        ans.push_back(vec);
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            vec.push_back(nums[i]);
            solve(i+1,nums,vec,ans);
            vec.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec;
        sort(nums.begin(),nums.end());
        solve(0,nums,vec,ans);
        return ans;
    }
};