class Solution {
public:
    int val;
    bool solve(unordered_map<int,int> &st, int pos, int last,map<pair<int,int>,int> &dp){
        //cout<<pos<<" "<<last<<" "<<ind<<"\n";
        if(pos==val){
            return true;
        }
        if(st.find(pos)==st.end()){
            return false;
        }
        if(dp.find({pos,last})!=dp.end()){
            return dp[{pos,last}];
        }
        if(last == 0){
           return dp[{pos,last}]=solve(st, pos+last+1, last+1,dp);
        }
        else if(last==1){
            return dp[{pos,last}]=solve(st, pos+last+1, last+1,dp)||solve(st,pos+last,last,dp);
        }
        
        else{
            return dp[{pos,last}]=(solve(st, pos+last+1, last+1,dp)||solve(st,pos+last-1,last-1,dp))||solve(st,pos+last,last,dp);
        }
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int,int> st;
        map<pair<int,int>,int> dp;
        for(int i = 0;i<stones.size();i++){
            st[stones[i]]++;
        }
        val = stones[stones.size()-1];
        return solve(st,0,0,dp);
    }
};