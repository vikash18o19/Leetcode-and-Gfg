class Solution {
public:
    int solve(int ind, int pos,vector<vector<int>>& tri,vector<vector<int>> &dp){
        if(ind == tri.size()) return 0;
        if(dp[ind][pos]!=-1){
            return dp[ind][pos];
        }
        int left;
        int right;
        
        left = tri[ind][pos]+solve(ind+1,pos,tri,dp);
        right = tri[ind][pos]+solve(ind+1,pos+1,tri,dp);
        
        return dp[ind][pos]=min(left,right);
    }
    int minimumTotal(vector<vector<int>>& tri) {
        vector<vector<int>> dp(tri.size(),vector<int>(tri[tri.size()-1].size(),-1));
        return solve(0,0,tri,dp);
    }
};