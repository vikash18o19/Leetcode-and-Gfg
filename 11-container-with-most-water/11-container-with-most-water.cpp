class Solution {
public:
    int maxArea(vector<int>& h) {
        int mx =INT_MIN;
        int low = 0;
        int high = h.size()-1;
        while(low<high){
            int ht = min(h[low],h[high]);
            int dist = high-low;
            mx=max(mx,ht*dist);
            if(h[low]<h[high]){
                low++;
            }
            else high--;
        }
        return mx;
        
    }
};