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
    map<string,int> mp;
    string solve(TreeNode* node,vector<TreeNode*> &ans){
        
        if(!node){
            return "#";
        }
        string s = solve(node->left, ans)+","+solve(node->right,ans)+","+to_string(node->val);
        mp[s]++;
        if(mp[s]==2){
            ans.push_back(node);
        }
        return s;
        
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        solve(root, ans);
        return ans;
    }
};