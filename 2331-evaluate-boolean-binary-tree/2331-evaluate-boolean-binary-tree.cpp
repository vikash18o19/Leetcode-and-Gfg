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
    bool solve(TreeNode* node){
        if(node->left==NULL && node->right==NULL){
            return node->val;
        }
        
        if(node->val==2){
            return solve(node->left) || solve(node->right);
        }
        else{
            return solve(node->left) && solve(node->right);
        }
    }
    bool evaluateTree(TreeNode* root) {
        return solve(root);
    }
};