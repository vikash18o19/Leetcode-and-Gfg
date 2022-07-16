class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n =nums.size();
        deque<int> mini;
        deque<int> maxi;
        
        int s =0;
        int e = 0;
        
        int count = 0;
        while(e<n){
            int num = nums[e];
            while(!mini.empty() && nums[mini.back()]>=num) mini.pop_back();
            mini.push_back(e);
            while(!maxi.empty() && nums[maxi.back()]<=num) maxi.pop_back();
            maxi.push_back(e);
            
            int val = nums[maxi.front()]-nums[mini.front()];
            if(val>limit){
                s++;
                if(s>mini.front()) mini.pop_front();
                if(s>maxi.front()) maxi.pop_front();
            }
            else{
                count=max(count,e-s+1);
                e++;
            }
            
        }
        
        return count;
    }
};