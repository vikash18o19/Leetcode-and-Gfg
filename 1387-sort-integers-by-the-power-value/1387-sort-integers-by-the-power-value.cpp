class Solution {
public:
    int solve(int x,map<int,int> &m){
        if(x==1){
            return 0;
        }
        if(m.find(x)!=m.end()){
            auto it = m.find(x);
            return(it->second);
        }
        if(x%2==0){
            return m[x]=1+solve(x/2,m);
        }
        else 
            return m[x]=1+solve((3 * x) + 1,m);
        
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> p;
        map<int,int> m;
        for(int i=lo;i<=hi;i++){
            int ans = solve(i,m);
            p.push_back(make_pair(ans,i));
        }
        sort(p.begin(),p.end());
        return p[k-1].second;
    }
};