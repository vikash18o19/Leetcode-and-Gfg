class Solution {
public:
    vector<string> printVertically(string s) {
        string temp="";
        int maxi=INT_MIN;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else{
                count++;
                int n=temp.size();
                maxi=max(maxi,n);
                temp.clear();
            }
        }
        count++;
        int n=temp.size();
        maxi=max(maxi,n);
        
        vector<string> ans(maxi,"");
        int cnt=0;
        int i=0;
        int j=0;
        while(i<s.size()){
            
            while(j<maxi){
                if(s[i]==' '){
                    ans[j]+=" ";
                    j++;
                }
                else{
                    ans[j]+=s[i];
                    j++;
                    i++;
                }
                
                if(i==s.size()){
                    break;
                }
            }
            j=0;
            if(s[i]==' '){
                i++;
            }
        }
        for(int ind = ans.size()-1;ind>=0;ind--){
            for(int si = ans[ind].size()-1;si>=0;si--){
                if(ans[ind][si]!=' '){
                    ans[ind].erase(si+1);
                    break;
                }
            }
        }
        return ans;
        
    }
};