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
    int minCut(string s) {
        vector<int> dp(s.size()+1,0);
        int n = s.size();
        for(int ind = n-1;ind>=0;ind--){
            priority_queue <int, vector<int>, greater<int>> pq;
            for(int i = ind; i<n; i++){
                if(palin(ind,i,s)){

                    pq.push(1 + dp[i+1]);

                }
            }
            dp[ind]=pq.top();
        }
        return dp[0]-1;
    }
};