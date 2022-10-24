class Solution {
public:
    string substr(string &exp,int a,int b){
        string temp ="";
        for(int i =a;i<=b;i++){
            temp+=exp[i];
        }
        return temp;
    }
    vector<int> solve(string exp){
        int n = exp.size();
        vector<int> ans;
        for(int i =0;i<n;i++){
            if(exp[i]=='-' || exp[i]=='*' || exp[i]=='+'){
                string a = substr(exp,0,i-1);
                string b = substr(exp,i+1,n-1);
                vector<int> v1 = solve(a);
                vector<int> v2 = solve(b);
                for(int x = 0;x<v1.size();x++){
                    for(int y = 0;y<v2.size();y++){
                        if(exp[i]=='-'){
                            ans.push_back(v1[x]-v2[y]);
                        }
                        if(exp[i]=='+'){
                            ans.push_back(v1[x]+v2[y]);
                        }
                        if(exp[i]=='*'){
                            ans.push_back(v1[x]*v2[y]);
                        }
                    }
                }
            }
        }
        if(ans.size()==0) ans.push_back(stoi(exp));
        return ans;
    }
    vector<int> diffWaysToCompute(string exp) {
        return solve(exp);
    }
};