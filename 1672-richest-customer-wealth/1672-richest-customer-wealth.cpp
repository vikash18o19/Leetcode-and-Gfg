class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int w = 0;
        int n = accounts.size();
        int m = accounts[0].size();
        int ans=INT_MIN;
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                w+=accounts[i][j];
            }
            ans=max(ans,w);
            w=0;
        }
        return ans;
    }
};