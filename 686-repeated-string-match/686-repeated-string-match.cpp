class Solution {
public:
    bool check(string a,string b){
        int n = a.size();
        int m = b.size();
        int k;
        for(int i =0;i<=n-m;i++){
            int j;
            k=1;
            for(j =0;j<m;j++){
                if(a[i+j]!=b[j]){
                    break;
                }
            }
            if(j==m){
                return true;
            }
            
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int m = a.size();
        int n = b.size();
        string temp = a;
        int ans = 1;
        while(temp.size()<n){
            temp+=a;
            ans++;
        }
        if(check(temp,b)){
            return ans;
        }
        if(check(temp+a,b)){
            return ans+1;
        }
        
        return -1;
        
    }
};