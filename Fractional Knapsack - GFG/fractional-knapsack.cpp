// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        priority_queue<pair<double,int>> val;
        for(int i = 0;i<n;i++){
            val.push({(double)arr[i].value/arr[i].weight,i});
        }
        int i=0;
        double profit = 0;
        while(i<n && W>=0){
            //cout<<val.top().first<<"\n";
            int ind = val.top().second;
            
            if(W>=arr[ind].weight){
                profit+=arr[ind].value;
                W-=arr[ind].weight;
            }
            else{
                profit+=val.top().first*W;
                W-=W;
            }
            val.pop();
            i++;
        }
        return profit;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends