class Solution {
public:
    void solve(int &n,int ind,vector<int>& nums, int target,
              vector<vector<int>> &ans,vector<int> temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(ind == n){
            return;
        }
        
        if(nums[ind]<=target){
            temp.push_back(nums[ind]);
            solve(n,ind,nums,target-nums[ind],ans,temp);
            temp.pop_back();
            solve(n,ind+1,nums,target,ans,temp);
        }
        else{
            solve(n,ind+1,nums,target,ans,temp);
        }
        return;
        
   
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(n,0,nums,target,ans,temp);
        return ans;
    }
};