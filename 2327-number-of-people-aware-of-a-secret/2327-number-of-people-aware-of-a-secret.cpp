class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> dp(n+1,0);
        long mod = (long)1e9 +7;
        long peep_sh=0;
        dp[1]=1;
        for(int i = 2;i<=n;i++){
            long f;
            f = dp[max(i-forget,0)];
            
            long nw;
            nw = dp[max(i-delay,0)];
            
            peep_sh+=(nw%mod-f%mod +mod)%mod;
            dp[i]=peep_sh;
        }
        long ans = 0;
        for(int i = n;i>n-forget;i--){
            ans = (ans%mod+ dp[i]%mod)%mod;
        }
        return (int)ans;
    }
};