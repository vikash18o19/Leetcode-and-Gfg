class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(int i =0;i<p.size();i++){
            mp[p[i]]++;
        }
        unordered_map<char,int> m;
        vector<int> ans;
        int t=0;
        int h=0;
        while(h<n){
            //cout<<t<<"---"<<h<<"\n";
            m[s[h]]++;
            if(h-t==p.size()-1){
                if(mp.find(s[h])!=mp.end()){
                    auto it=m.begin();
                    
                    while(it!=m.end()){
                        
                        if(mp.find(it->first)==mp.end() || it->second!=mp.find(it->first)->second){
                            break;
                        }
                        it++;
                    }
                    if(it==m.end()){
                        ans.push_back(t);
                    }
                }
                m[s[t]]--;
                if(m[s[t]]==0){
                    m.erase(s[t]);
                }
                t++;
            }
            h++;
        }
        return ans;
    }
};