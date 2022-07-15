/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector(n,-1));
        
        int dr[] = { 0, 1, 0, -1 };
        int dc[] = { 1, 0, -1, 0 };
        
        int x=0,y=0,di=0;
        for(int i=0;i<m*n;i++){
            //cout<<x<<" "<<y<<" "<<di<<"\n";
            if(head==NULL){
                break;
            }
            int val = head->val;
            head=head->next;
            ans[x][y]=val;
            
            int nx = x+dr[di];
            int ny = y+dc[di];
            
            if(0<=nx && nx<m && 0<=ny && ny<n && ans[nx][ny]==-1){
                //if(ans[nx][ny]==-1){
                    x=nx;
                    y=ny;
                //}
            }
            else{
                
                di = (di + 1) % 4;
                //cout<<"direction index changed to: "<<di<<"\n";
                x += dr[di];
                y += dc[di];
            }
        }
        return ans;
    }
};