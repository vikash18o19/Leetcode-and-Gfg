class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string pal ="";
        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
                char temp = tolower(s[i]);
                pal+=temp;
            }
        }
        bool check = true;
        int l = pal.size();
        int lo =0;
        int hi=l-1;
        
        while(lo<hi){
            if(pal[lo]!=pal[hi]){
                check =false;
                break;
            }
            lo++;
            hi--;
        }
        return check;
    }
};