class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int ans =0;
        for(int i =0;i<=200;i++){
            for(int j =0;j<=200;j++){
                bool flag=false;
                for(int c = 0;c<circles.size();c++){
                    int l = (i-circles[c][0])*(i-circles[c][0]) + 
                        (j-circles[c][1])*(j-circles[c][1]);
                    if(l<=(circles[c][2]*circles[c][2])){
                        flag=true;
                        break;
                    }
                }
                if(flag==true){
                    ans++;
                }
            }
        }
        return ans;
    }
};