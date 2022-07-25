class Solution {
public:
    double myPow(double x, int n) {
        double ans= 1.0;
        long nn = n;
        if(n<0) nn=  (long)-1*n;
        while(nn>0){
            if(nn%2==1){
                ans = ans*x;
                nn-=1;
            }
            else{
                x=x*x;
                nn = nn/2;
            }
        }
        if(n<0) ans = (double)1/(double)ans;
        return ans;
    }
};