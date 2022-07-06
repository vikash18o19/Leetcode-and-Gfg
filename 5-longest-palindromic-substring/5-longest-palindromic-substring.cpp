class Solution {
public:
    string sub(int lo, int hi, string &s){
        string res ="";
        for(int i = lo;i<=hi;i++){
            res+=s[i];
        }
        return res;
    }
    int give(int i, int j, string &s){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        return j-i-1;
    }
    string longestPalindrome(string s) {
        int lo = 0,hi=0;
        
        for(int i =0;i<s.size();i++){
            int len1 = give(i,i,s);
            int len2 = give(i,i+1,s);
            int len = max(len1,len2);
            if(hi-lo<len){
                
                lo = i - (len-1)/2;
                hi = i+(len)/2;
            }
        }
        return sub(lo,hi,s);
    }
};