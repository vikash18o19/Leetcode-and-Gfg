class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n-1;
        int flag = 0;
        int count = 0;
        while(i>=0){
            if(flag==0){
                if(s[i]!=' '){
                    flag=1;
                    count++;
                }
            }
            else if(flag==1){
                if(s[i]!=' '){
                    count++;
                }
                else{
                    break;
                }
            }
            i--;
        }
        return count;
    }
};