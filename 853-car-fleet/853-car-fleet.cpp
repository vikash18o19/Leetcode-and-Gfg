class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& sp) {
        int n = pos.size();
        vector<pair<float,float>> car(n,{0,0});
        for(int i=0;i<n;i++){
            car[i].second=float(target-pos[i])/sp[i];
            //cout<<target-pos[i]<<"/"<<sp[i]<<"="<<car[i].second<<"\n";
            //float check = 4/3;
            //cout<<"\n"<<check;
            //cout<<car[i].second;
            car[i].first = pos[i];
        }
        sort(car.begin(),car.end());
        int count = 0;
        float temp = car[n-1].second;
        for(int i =n-2;i>=0;i--){
            //cout<<temp<<" "<<car[i].second<<"\n";
            if(car[i].second > temp){
                count++;
                temp = car[i].second;
            }
        }
        
        return count+1;
        
    }
};