class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> h;
        h.push(amount[0]);h.push(amount[1]);h.push(amount[2]);
        int count=0;
        while(h.top()!=0){
            int temp1 = h.top();
            h.pop();
            int temp2 = h.top();
            if(temp2!=0){
                h.pop();
                temp2-=1;
                h.push(temp2);
            }
            temp1-=1;
            h.push(temp1);
            count++;
        }
        return count;
    }
};