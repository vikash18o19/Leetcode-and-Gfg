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
    bool solve(TreeNode *node, int &t,int sum, TreeNode *p){
        if(node==NULL)
        {
            if(sum==t && p->left==NULL && p->right==NULL)
                return true;
            else 
                return false;
        }
        
       
        return solve(node->left,t,sum+node->val,node) || solve(node->right,t,sum+node->val,node); 
        
        
    }
    bool hasPathSum(TreeNode* root, int t) {
        //int sum = 0;
        //vector<int> check()
        
        if(root==NULL){
            return false;
        }
        
        
        return solve(root,t,0,root);
        
    }
};