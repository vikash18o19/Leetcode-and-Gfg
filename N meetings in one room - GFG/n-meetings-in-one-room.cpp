// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{

    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        for(int i=0;i<n;i++){
            pq.push({end[i],start[i]});
        }
        int count = 0;
        int st = INT_MIN;
        for(int i = 0;i<n;i++){
            if(pq.top().second>st){
                count++;
                st = pq.top().first;
            }
            pq.pop();
        }
        return count;
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends