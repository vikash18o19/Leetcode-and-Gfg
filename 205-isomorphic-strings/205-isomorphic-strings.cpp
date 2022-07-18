class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char,char> mp;
        unordered_map<char,int> m;
        for(int i =0;i<n;i++){
            //if(s[i]==t[i]) return false;
            if(m.find(t[i])!=m.end()){
               if(mp.find(s[i])==mp.end()){
                    return false;
                }
            }
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]!=t[i]){
                    return false;
                }
            }
            else{
                mp[s[i]]=t[i];
                m[t[i]]++;
            }
        }
        return true;
    }
};