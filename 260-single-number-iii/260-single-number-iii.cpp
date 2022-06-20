class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
         int n=nums.size();
        int temp;
        int count=0;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(count==0){
                temp=nums[i];
                count++;
            }
            else if(count<2){
                if(temp==nums[i]) count++;
                else 
                {
                    ans.push_back(temp);
                    temp=nums[i];
                    count =1;
                }
            }
            if(count==2) count=0;
        }
        cout<<temp;
        if(ans.size()==1)ans.push_back(temp);
        return ans;
    }
};
