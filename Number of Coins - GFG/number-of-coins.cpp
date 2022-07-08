// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int solve(int ind, int v, int n, int coins[],vector<vector<int>> &dp){
	    if(ind==n){
	        return 1e9;
	    }
	    
	    if(v==0){
	        return 0;
	    }
	    
	    if(dp[ind][v]!=-1){
	        return dp[ind][v];
	    }
	    int take = INT_MAX;
	    if(coins[ind]<=v){
	        take = 1+solve(ind,v-coins[ind],n,coins,dp);
	    }
	    int not_take = solve(ind+1,v,n,coins,dp);
	    //cout<<min(take,not_take)<<"\n";
	    return dp[ind][v]=min(take,not_take);
	}
	int minCoins(int coins[], int n, int v) 
	{ 
	    
	    vector<vector<int>> dp(n+1,vector<int>(v+1,-1));
	    int ans = solve(0,v,n,coins,dp);
	    if(ans>=1e9){
	        return -1;
	    }
	    else{
	        return ans;
	    }
	    
	    
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends