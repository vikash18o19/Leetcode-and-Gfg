class Solution {
public:
    int comp(vector<vector<int>>& students, 
             vector<vector<int>>& mentors,int s,int m){
        int count =0;
        for(int i =0;i<students[0].size();i++){
            if(mentors[m][i]==students[s][i]){
                count++;
            }
        }
        return count;
    }
    void solve(int ind, vector<vector<int>>& students, vector<vector<int>>& mentors, vector<bool> mnt,int &res, int score){
        if(ind==students.size()){
            res = max(res,score);
            return;
        }
        
        int compScore=0;
        for(int i =0;i<students.size();i++){
            if(mnt[i]==false){
                mnt[i]=true;
                compScore = comp(students,mentors,i,ind);
                solve(ind+1,students,mentors,mnt,res,score+compScore);
                mnt[i]=false;
            }
        }
        
        
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m  = students.size();
        int n  = students[0].size();
        vector<bool> mnt(m,false);
        int res = 0;
        int score = 0;
        solve(0,students,mentors,mnt,res,score);
        return res;
    }
};