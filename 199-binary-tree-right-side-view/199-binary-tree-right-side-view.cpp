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
    void solve(vector<int> &ans, TreeNode* node, int &mx,int ch){
        if(node==NULL) return;
        if(ch>mx){
            ans.push_back(node->val);
            mx=ch;
        }
        solve(ans,node->right,mx,ch+1);
        solve(ans,node->left,mx,ch+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return {};
        int mx = 1; 
        ans.push_back(root->val);
        solve(ans,root,mx,1);
        return ans;
    }
};