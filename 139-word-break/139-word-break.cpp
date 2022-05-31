class Solution {
public:
    bool solve(int ind, string &s, set<string>& d, vector<int> &dp){
        if(ind==s.size()){
            return 1;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        string temp;
        for(int i =ind;i<s.size();i++){
            temp += s[i];
            if(d.find(temp)!=d.end()){
                cout<<*d.find(temp)<<" ";
                if(solve(i+1,s,d,dp)) return dp[ind]=1;
            }
        }
        return dp[ind] = 0;
        
    } 
    
    bool wordBreak(string s, vector<string>& dict) {
        set<string> d;
        vector<int> dp(s.size()+1,0);
        for(int j = 0; j<dict.size();j++){
            d.insert(dict[j]);
        }
        dp[s.size()]=1;
        for(int ind = s.size()-1;ind>=0;ind--){
            string temp;
            for(int i =ind;i<s.size();i++){
                temp += s[i];
                if(d.find(temp)!=d.end()){
                    //cout<<*d.find(temp)<<" ";
                    if(dp[i+1])  dp[ind]=1;
                }
            }
             //dp[ind] = 0;
        }
        return dp[0];
    }
};