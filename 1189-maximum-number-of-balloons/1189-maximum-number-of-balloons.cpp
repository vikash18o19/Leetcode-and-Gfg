class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        int n = text.size();
        for(int i =0;i<n;i++){
            if(text[i]=='b'||text[i]=='a'||text[i]=='l'||text[i]=='o'||
               text[i]=='n')
                mp[text[i]]++;
        }
        string b="balon";
        int ans = INT_MAX;
        for(int i =0;i<5;i++){
            if(mp.find(b[i])==mp.end()){
                return 0;
            }
            else{
                //cout<<mp[b[i]]<<"\n";
                if(i==3||i==2){
                    int temp = mp[b[i]]/2;
                    ans=min(ans,temp);
                }
                else{
                    ans=min(ans,mp[b[i]]);
                }
            }
        }
        return ans;
    }
};