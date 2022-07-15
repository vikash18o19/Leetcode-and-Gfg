class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char,int> mp;
        int count = 0;
        for(int i =0;i<key.size();i++){
            if(mp.size()==26){
                break;
            }
            if(mp.find(key[i])==mp.end() && key[i]!=' '){
                //cout<<key[i];
                mp[key[i]]=count;
                count++;
            }
        }
        //cout<<"\n";
        
        string ans="";
        for(int i =0;i<message.size();i++){
            //cout<<ans<<"\n";
            if(message[i]==' '){
                ans+=' ';
            }
            
            else{
                int ind = mp[message[i]];
                char mes = (char)('a'+ind);
                ans+=mes;
            }
        }
        return ans;
    }
};