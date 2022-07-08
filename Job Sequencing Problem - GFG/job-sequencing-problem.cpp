// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        priority_queue<pair<int,int>> pq;
        int max_d=INT_MIN;
        for(int i =0;i<n;i++){
            max_d=max(max_d,arr[i].dead);
            pq.push({arr[i].profit,i});
        }
        vector<int> v(max_d+1,-1);
        int profit=0;
        int count =0;
        for(int i =0;i<n;i++){
            int pr = pq.top().first;
            int ind = pq.top().second;
            int d = arr[ind].dead;
            //cout<<"dead: "<<d<<" profit: "<<arr[ind].profit<<"\n";
            while(d>=1){
                if(v[d]==-1){
                    v[d]=ind+1;
                    count++;
                    profit+=arr[ind].profit;    
                    break;
                }
                d--;
            }
            
            pq.pop();
        }
        //int num = mp.size();
        //cout<<num;
        
        return {count,profit};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends