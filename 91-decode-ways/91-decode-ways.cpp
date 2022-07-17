class Solution {
public:
    int solve(int ind, string &s, int &count, vector<int> &dp){
        int n = s.size();
        if(ind>=n){
            return 1;
        }
        if(dp[ind]!=-1)
            return dp[ind];
        if(s[ind]=='0'){
            return dp[ind]=0;
        }
        string temp = "";
        temp+=s[ind];
        int a=0,b;
        if(ind+1<n){
            temp+=s[ind+1];
            if(stoi(temp)<=26){
                a=solve(ind+2,s,count,dp);
            }
        }
        b=solve(ind+1,s,count,dp);
        return dp[ind]=a+b;
    }
    int numDecodings(string s) {
        int count=0;
        vector<int> dp(s.size(),-1);
        return solve(0,s,count,dp);
    }
};