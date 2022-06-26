/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* p, TreeNode* q, bool &ans){
        //cout<<p->val<<" "<<q->val<<"   ";
        
        if(p==NULL || q==NULL){
            if(p==NULL && q==NULL)
                return;
            else{
                ans=0;
                return;
            }
                
            
        }
        
        if(p->val!=q->val){
            ans=0;
        }
        
        
        solve(p->left,q->left,ans);
        solve(p->right,q->right,ans);
        
        return;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans=1;
        solve(p,q,ans);
        return ans;
    }
};