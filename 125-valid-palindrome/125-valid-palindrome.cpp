class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string original = "";
        for(int i=0;i<n;i++) {
            if(isalnum(s[i])) {
                original += tolower(s[i]);
            }
        }
        int size = original.size();
        int i=0, j=size-1;
        while(i<=j) {
            if(original[i]!=original[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};