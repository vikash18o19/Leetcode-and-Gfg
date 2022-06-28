class Solution {
public:
    void solve(string &digits,vector<string> &str,vector<string> &ans,string s,int ind){
        if(ind == digits.size()){
            ans.push_back(s);
            return;
        }
        for(int i =0;i<str[digits[ind]-'0'].size();i++){
            solve(digits,str,ans,s+str[digits[ind]-'0'][i],ind+1);
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> str{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        if(digits.size()==0){
            return ans;
        }
        string s="";
        solve(digits,str,ans,s,0);
        return ans;
    }
};