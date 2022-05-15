class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int num = x;
        vector<int> n;
        //vector<int> rn;
        while(num!=0){
            n.push_back(num%10);
            num=num/10;
        }
        if(n.size()==0){
            n.push_back(0);
        }
        int j=n.size()-1;
        int flag=0;
        for(int i = 0;i<=n.size()/2 ; i++){
            cout<<n[i]<<" "<<n[j]<<"\n";
            if(n[i]!=n[j]){
                flag=1;
                break;
            }
            j--;
        }
        if(flag==1){
            return false;
        }
        else
            return true;
    }
};