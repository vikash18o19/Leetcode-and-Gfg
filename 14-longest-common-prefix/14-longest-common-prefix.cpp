class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int count = 0;
        int mn = INT_MAX;
        for(int i =0;i<n;i++){
            int s = strs[i].size();
            mn = min(mn,s);
        }
        int i =0;
        string ans ="";
        while(i<mn){
            char temp =strs[0][i];
            int flag=1;
            for(int j =0;j<n;j++){
                if(strs[j][i]!=temp){
                    flag=0;
                    break;
                }
            }
            if(flag==0){
                break;
            }
            else{
                ans+=temp;
            }
            i++;
        }
        return ans;
    }
};