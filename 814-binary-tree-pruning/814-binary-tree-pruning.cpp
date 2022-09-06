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
    bool helper(TreeNode*root){
        if(root==NULL){
            return false;
        }
        bool leftans=helper(root->left);
        bool rightans=helper(root->right);
        if(leftans==false) root->left=NULL;
        if(rightans==false) root->right=NULL;
        return root->val==1 || leftans || rightans;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return NULL;
        bool ans=helper(root);
        if(ans==false) return NULL;
        else
            return root;
    }
};