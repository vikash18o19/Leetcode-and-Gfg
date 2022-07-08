// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<vector<int>> &m,int i,int j,
        int &n,string temp,vector<string> &ans){
        if(m[i][j]==0){
            return;
        }
        if(i==n-1 && j==n-1){
            ans.push_back(temp);
            return;
        }
        string str = temp;
        int val = m[i][j];
        m[i][j]=2;
        if(i+1<n){
            if(m[i+1][j]!=2){
                str+='D';
                solve(m,i+1,j,n,str,ans);
                str.pop_back();
            }
        }
        if(j+1<n){
            if(m[i][j+1]!=2){
                str+='R';
                solve(m,i,j+1,n,str,ans);
                str.pop_back();
            }
        }
        if(i-1>=0){
            if(m[i-1][j]!=2){
                str+='U';
                solve(m,i-1,j,n,str,ans);
                str.pop_back();
            }
        }
        if(j-1>=0){
            if(m[i][j-1]!=2){
                str+='L';
                solve(m,i,j-1,n,str,ans);
                str.pop_back();
            }
        }
        m[i][j]=val;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        solve(m,0,0,n,"",ans);
        
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends