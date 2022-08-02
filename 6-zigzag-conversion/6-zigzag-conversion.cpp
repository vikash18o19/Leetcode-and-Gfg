class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        int i = 0;
        vector<string> str(numRows,"");
        int flag=0;
        int ind =0;
        while(i<s.size()){
            while(flag==0 && i<s.size()){

                str[ind]+=s[i];
                i++;
                if(ind<numRows-1){
                    ind++;
                }
                else if(ind==numRows-1){
                    ind--;
                    flag=1;
                }    
            }
            while(flag==1 && i<s.size()){
                str[ind]+=s[i];
                i++;
                if(ind>0){
                    ind--;
                }
                else if(ind==0){
                    ind++;
                    flag=0;
                }
            }
        }
        string ans="";
        for(int i = 0; i<numRows;i++){
            ans+=str[i];
        }
        return ans;
        
    }
};