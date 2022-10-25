class Solution {
public:
    void solve(vector<int> &d, int ind){
        
        if(d[ind]<9){
            d[ind]++;
        }
        else if(d[ind]==9){
            d[ind]=0;
            if(ind==d.size()-1){
               d.push_back(1);
            }
            else
                solve(d,ind+1);
        }
        return;
    }
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        solve(digits,0);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};