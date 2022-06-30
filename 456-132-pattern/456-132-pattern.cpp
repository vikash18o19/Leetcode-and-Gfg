class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> mn(n,-1);
        mn[0]=nums[0];
        for(int i = 1;i<n;i++){
            if(nums[i]<mn[i-1]){
                mn[i]=nums[i];
            }
            else{
                mn[i]=mn[i-1];
            }
        }
        // for(int i = 0;i<n;i++){
        //     cout<<mn[i]<<" ";
        // }
        stack<int> st;
        
        for(int j = n-1;j>=0;j--){
            
            while(!st.empty() && st.top()<=mn[j])
                st.pop();
            
            
            if(!st.empty() && st.top()<nums[j]){
                    return true;
            }
            
            
            st.push(nums[j]);
            
        }
        return false;
        
    }
};