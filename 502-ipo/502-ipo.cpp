typedef pair<int,int> ii;



class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<ii, vector<ii>, greater<ii>> projects_pq;        
        priority_queue <int> feasible;
        for(int i =0;i<n;i++){
            projects_pq.push({capital[i],profits[i]});
        }
        
        
        while(k--){
            while(!projects_pq.empty() && projects_pq.top().first<=w){
                feasible.push(projects_pq.top().second);
                projects_pq.pop();
            }
            if(feasible.empty()) return w;
            w+=feasible.top();
            feasible.pop();
        }
        return w;
    }
};