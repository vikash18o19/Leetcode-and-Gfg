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
    void solve(TreeNode* node, vector<string> &ans, string temp){
        if(node->left==NULL && node->right==NULL){
            temp+=to_string(node->val);
            ans.push_back(temp);
            return;
        }
        
        temp+=to_string(node->val);
        temp+="->";
        if(node->left!=NULL)
            solve(node->left,ans,temp);
        if(node->right!=NULL)
            solve(node->right,ans,temp);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp = "";
        solve(root,ans,temp);
        return ans;
    }
};