class Solution {
public:
    unordered_map<string,bool> dp;
    bool solve(string &s1, string &s2, string &s3, int &l1, 
               int &l2, int &l3, int p1, int p2, int p3){
        //cout<<p1<<"*"<<p2<<"*"<<p3<<"\n";
        if(p3==l3){
            if(p1==l1 && p2==l2) return true;
            else return false;
        }
        string key = to_string(p1)+"*"+to_string(p2)+
            "*"+to_string(p3);
        
        if(dp.find(key)!=dp.end()) {
            return dp[key];
        };
        
        if(p1==l1){
            return dp[key]=(s2[p2]==s3[p3])?solve(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1):false;
        }
        if(p2==l2){
            return dp[key]=(s1[p1]==s3[p3])?solve(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1):false;
        }
        
        bool a = false;
        bool b = false;
        
        if(s1[p1]==s3[p3]) a = solve(s1,s2,s3,l1,l2,l3,p1+1,p2,p3+1);
        if(s2[p2]==s3[p3]) b = solve(s1,s2,s3,l1,l2,l3,p1,p2+1,p3+1);
        
        return dp[key]=(a||b);
    }
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();
        
        if(l3!=l1+l2) return false;
        
        return solve(s1,s2,s3,l1,l2,l3,0,0,0);
    }
};