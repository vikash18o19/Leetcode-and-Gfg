class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue <int, vector<int>, greater<int> > pq;
        int n=h.size();
        for(int i=0;i<n-1;i++){
            int diff = h[i+1]-h[i];
            if(diff>0){
                if(l){
                    pq.push(diff);
                    l--;
                }
                else if(!pq.empty() && diff> pq.top()){
                    pq.push(diff); 
                    b -= pq.top(); 
                    pq.pop();
                }
                else 
                    b -= diff;
                if (b < 0) return i;
            }
        }
        return n-1;
    }
};