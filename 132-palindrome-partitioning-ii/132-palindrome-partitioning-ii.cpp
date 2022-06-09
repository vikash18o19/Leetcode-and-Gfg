class Solution {
public:
    
    bool palin(int l, int h, string &s){
        while(l<h){
            if(s[l]!=s[h]){
                return false;
            }
            l++;
            h--;
        }
        return true;
    }
    int solve(string &s, int ind, int n,vector<int> &dp){
        
        if(ind == s.size()){
            return 0;
        }
         if(dp[ind]!=-1){
             return dp[ind];
         }
        priority_queue <int, vector<int>, greater<int>> pq;
        for(int i = ind; i<n; i++){
            if(palin(ind,i,s)){
                
                pq.push(1 + solve(s,i+1,n,dp));
                
            }
        }
        return dp[ind]=pq.top();
    }
    int minCut(string s) {
        vector<int> dp(s.size(),-1);
        int n = s.size();
        int out = solve(s,0,n,dp);
        return out-1;
    }
};