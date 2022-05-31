class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> max_l;
        vector<int> max_r;
        max_l.push_back(0);
        int temp =0; 
        for(int i = 1;i<n;i++){
            temp=max(h[i-1],temp);
            max_l.push_back(temp);
        }
        
        max_r.push_back(0);
        temp =0; 
        for(int i = n-2;i>=0;i--){
            temp=max(h[i+1],temp);
            max_r.push_back(temp);
        }
        reverse(max_r.begin(),max_r.end());
        int sum = 0;
        for(int i = 0;i<n;i++){
            int x = min(max_l[i],max_r[i]);
            if(h[i]<x){
                sum+=x-h[i];
            }
        }
        return sum;
    }
};