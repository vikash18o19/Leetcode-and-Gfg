class Solution {
public:
    string getHint(string secret, string guess) {
        map<char,int> mp;
        int a =0;
        int b =0;
        for(int i =0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                a++;
                continue;
            }
            mp[secret[i]]++;
        }
        
        for(int i =0;i<guess.size();i++){
            if(secret[i]!=guess[i]){
                if(mp.find(guess[i])!=mp.end() && mp[guess[i]]!=0){
                    b++;
                    mp[guess[i]]--;
                }
            }
        }
        return to_string(a)+"A"+to_string(b)+"B";
    }
};