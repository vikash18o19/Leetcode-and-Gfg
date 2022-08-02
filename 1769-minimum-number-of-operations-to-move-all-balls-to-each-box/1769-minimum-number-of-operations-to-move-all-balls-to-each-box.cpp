class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> l(n,0);
        vector<int> r(n,0);
        int cl = boxes[0]-'0';
        for(int i =1;i<n;i++){
            l[i]=cl+l[i-1];
            cl+=boxes[i]-'0';
            
        }
        int cr = boxes[n-1]-'0';
        for(int i =n-2;i>=0;i--){
           
            r[i] = cr+r[i+1];
            cr+=boxes[i]-'0';
        }
        for(int i =0;i<n;i++){
            l[i]+=r[i];
        }
        return l;
    }
};