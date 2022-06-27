class Solution {
public:
    
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        string a="11";
        
        for(int i = 3;i<=n;i++ ){
            string temp = "";
            int count = 1;
            a=a+"$";
            for(int j = 1;j<a.size();j++){
                if(a[j]==a[j-1]){
                    count++;
                }
                else{
                    temp+=to_string(count);
                    temp+=a[j-1];
                    count=1;
                }
            }
            a=temp;
        }
        
        
        return a;
    }
};