class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 0;
        }
        vector<int> l(n,0);
        vector<int> r(n,0);
        int l_sum=0;
        int r_sum=0;
        for(int i =0;i<n;i++){
            int ind_r = n-i-1;
            l_sum+=nums[i];
            r_sum+=nums[ind_r];
            l[i]=l_sum;
            r[ind_r]=r_sum;
        }
        for(int i =0;i<n;i++){
            if(i==0){
                if(r[i+1]==0){
                    return 0;
                }
            }
            else if(i==n-1){
                if(l[i-1]==0){
                    return n-1;
                }
            }
            else if(l[i-1]==r[i+1]){
                return i;
            }
        }
        return -1;
    }
};