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
    /*
        p.first= height;
        p.second=diameter
        
    */
    
    int height(TreeNode*root){
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int h1=diameterOfBinaryTree(root->left);
        int h2=diameterOfBinaryTree(root->right);
        int h3=height(root->left)+height(root->right);
        return max(h1,max(h2,h3));
    }
};