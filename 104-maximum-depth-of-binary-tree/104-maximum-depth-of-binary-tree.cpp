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
    void ht(TreeNode* root, int cur_h,int &mx){
        if(root==NULL){
            return;
        }
        if(cur_h>mx){
            mx=cur_h;
        }
        ht(root->left,cur_h+1,mx);
        ht(root->right,cur_h+1,mx);
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int mx=0;
        ht(root,0,mx);
        return mx+1;
    }
};