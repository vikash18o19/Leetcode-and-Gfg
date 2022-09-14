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
    void solve(TreeNode* node, int &ans, int &mx, int cl){
        if(node==NULL) return;
        
        if(cl>mx){
            mx=cl;
            ans = node->val;
        }
        solve(node->left,ans,mx,cl+1);
        solve(node->right,ans,mx,cl+1);
        
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans;
        int mx =1;
        ans =root->val;
        solve(root, ans, mx, 1);
        return ans;
    }
};