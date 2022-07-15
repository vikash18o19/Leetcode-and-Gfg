class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0){
            return 0;
        }
        map<char,int> mp;
        int mx = 0;
        int l = 0;
        int r =0;
        while(l<n && r<n){
            if(mp.find(s[r])!=mp.end()){
                l = max(mp[s[r]]+1,l);
            }
            mp[s[r]]=r;
            mx=max(mx,r-l+1);
            r++;
        }
        return mx;
    }
};