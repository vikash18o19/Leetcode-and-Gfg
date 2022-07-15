class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0){
            return 0;
        }
        map<char,int> mp;
        int mx = INT_MIN;
        for(int i =0;i<n;i++){
            int count =0;
            for(int j=i;j<n;j++){
                if(mp.find(s[j])==mp.end()){
                    count++;
                    mp[s[j]]++;
                }
                else{
                    break;
                }
            }
            mx = max(mx,count);
            mp.clear();
        }
        return mx;
    }
};