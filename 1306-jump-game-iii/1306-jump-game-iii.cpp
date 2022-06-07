class Solution {
public:
    void solve(vector<int>& arr, int ind, vector<int> &visit,int &flag){
        //cout<<"visited index: "<<ind<<"\n";
        visit[ind]=0;
        if(arr[ind]==0){
            flag=1;
            return;
        }
        
        int i= -1*arr[ind];
        if((ind+i>=0 && ind+i<arr.size()) && (i!=0 && visit[ind+i]==-1)){
            solve(arr,ind+i,visit,flag);
        }
        i = arr[ind];    
        if((ind+i>=0 && ind+i<arr.size()) && (i!=0 && visit[ind+i]==-1)){
            solve(arr,ind+i,visit,flag);
        }
        return ;
    }
    bool canReach(vector<int>& arr, int start) {
        int flag=0;
        vector<int> visit(arr.size(),-1);
        solve(arr,start,visit,flag);
        // for(int i =0;i<arr.size();i++){
        //     cout<<visit[i]<<" ";
        // }
        return flag;
    }
};