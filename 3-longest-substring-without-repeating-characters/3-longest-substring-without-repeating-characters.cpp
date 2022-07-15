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
            while(mp.find(s[r])==mp.end() && r<n){
                mp[s[r]]++;
                int size = r-l+1;
                mx= max(mx,size);
                r++;
            }
            while(mp.find(s[r])!=mp.end() && l<=r){
                mp.erase(s[l]);
                l++;
            }
        }
        return mx;
    }
};