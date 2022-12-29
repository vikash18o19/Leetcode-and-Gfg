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
    void preorder(TreeNode* root, vector<int> &pre){
        if(root==NULL){
            pre.push_back(-101);
            return;
        }
        pre.push_back(root->val);
        preorder(root->left, pre);
        preorder(root->right, pre);
    }
    void postorder(TreeNode* root, vector<int> &post){
        if(root==NULL){
            post.push_back(-101);
            return;
        }
        postorder(root->left, post);
        postorder(root->right, post);
        post.push_back(root->val);
    }
    bool isSymmetric(TreeNode* root) {
        vector<int> pre;
        vector<int> post;
        preorder(root, pre);
        postorder(root, post);
        reverse(post.begin(),post.end());
        int a = min(pre.size(), post.size());
        // for(int i=0;i<a;i++){
        //     cout<<pre[i]<<" ";
        // }
        // cout<<"\n";
        // for(int i=0;i<a;i++){
        //     cout<<post[i]<<" ";
        // }   
        for(int i=0;i<a;i++){
            if(pre[i]!=post[i]) return 0;
        }   
        return 1;
    }
};