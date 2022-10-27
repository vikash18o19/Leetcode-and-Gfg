class Solution {
public:
    int strStr(string hay, string needle) {
        int ans=-1;
        int n = needle.size();
        int h = hay.size();
        if(n>h){
            return -1;
        }
        
        for(int i =0;i<h;i++){
            if(hay[i]==needle[0]){
                int temp = i;
                int j;
                for(j = 0;j<n;j++){
                    
                    if(i+j<h){
                        if(hay[i+j]==needle[j]){
                        continue;
                        }
                        else{
                            break;
                        }
                     }
                    if(i+j>=h){
                        break;
                    }
                }
                if(j==n){
                    ans=temp;
                    break;
                }
            }    
        }
        return ans;
    }
};