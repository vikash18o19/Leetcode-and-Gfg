class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans =0;
        for(int i = 0;i<s.size();i++){
            for(int j=0;j<t.size();j++){
                int a=i;
                int b=j;
                int dif=0;
                while(a<s.size() && b<t.size()){
                    if(s[a]!=t[b]) dif++;
                    if(dif==1) ans++;
                    if(dif==2) break;
                    a++;
                    b++;
                }
            }
        }
        return ans;
    }
};