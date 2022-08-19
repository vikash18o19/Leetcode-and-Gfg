class Solution {
public:
    int numTeams(vector<int>& nums) {
        int n=nums.size();
        vector<int>bigger_to_left(n,0);
        vector<int>smaller_to_left(n,0);
        for(int i=0;i<n;i++){
            int big=0,small=0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])small++;
                else big++;
            }
            bigger_to_left[i]=big;
            smaller_to_left[i]=small;
        }
        int teams=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                //5 9
                if(nums[i]<nums[j])
                    teams+=smaller_to_left[i];
                //5 1
                else
                    teams+=bigger_to_left[i];
            }
        }
        return teams;
    }
}; 