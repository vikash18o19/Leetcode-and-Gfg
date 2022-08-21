class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int m = bank.size();
        int n = bank[0].size();
        int tot = 0;
        for(int i = 0;i<m;i++){
            int dev = 0;
            for(int j =0;j<n;j++){
                if(bank[i][j]=='1'){
                    dev++;
                }
            }
            tot+=prev*dev;
            if(dev!=0){
                prev=dev;
            }
            
        }
        return tot;
    }
};