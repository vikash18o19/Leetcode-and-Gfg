//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dp[505][2005];
    int solve(int i,int rem, vector<int> &nums, int &k){
        if(i == nums.size()){
            return 0;
        }
        if(dp[i][rem]!=-1){
            return dp[i][rem];
        }
        int ans;
        if(nums[i]>rem){
            ans = (rem+1)*(rem+1)+solve(i+1,k-nums[i]-1,nums,k);
        }
        else{
            int c1;
            int c2;
            c1 = solve(i+1,rem-nums[i]-1,nums,k);
            c2 = (rem+1)*(rem+1)+solve(i+1,k-nums[i]-1,nums,k);
            ans = min(c1,c2);
        }
        dp[i][rem]=ans;
        return dp[i][rem];
        
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        memset(dp,-1,sizeof(dp));
        return solve(0,k,nums,k);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends
