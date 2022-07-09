class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        for(int i =0;i<n;i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int> , vector<pair<int,int>>
            , greater<pair<int,int>>> pq;
        for(auto i =mp.begin();i!=mp.end();i++){
            //cout<<"digit: "<<i->first<<" frq: "<<i->second<<"\n";
            pq.push({i->second,i->first});
            //cout<<"top: "<<pq.top().second<<"\n";
            if(pq.size()>k){
                //cout<<"popped: "<<pq.top().second<<"\n";
                pq.pop();
            }
        }
        vector<int> ans;
        for(int i =0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};