class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int m = tri.size();
        int n = tri[m-1].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int ind = m-1;ind>=0;ind--){
            for(int pos = n-1-(m-1-ind);pos>=0;pos--){
                
                int left = tri[ind][pos]+dp[ind+1][pos];
                int right = tri[ind][pos]+dp[ind+1][pos+1];

                dp[ind][pos]=min(left,right);
            }
        }
        return dp[0][0];
    }
};