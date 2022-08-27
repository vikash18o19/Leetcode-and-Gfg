class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        vector<char> temp(s.size(),'a');
        string ans="";
        for(int  i =0;i<s.size();i++){
            temp[indices[i]]=s[i];
        }
        for(int  i =0;i<s.size();i++){
            ans+=temp[i];
        }
        
        return ans;
    }
};