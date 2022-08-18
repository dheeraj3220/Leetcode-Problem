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
    
    // int height(TreeNode*root){
    //     if(root==NULL) return 0;
    //     return 1+max(height(root->left),height(root->right));
    // }
    
    pair<int,int> helper(TreeNode*root){
        pair<int,int> p;
        if(root==NULL) {
            p.first=0;
            p.second=0;
            return p;
        }
        pair<int,int> leftans=helper(root->left);
        pair<int,int> rightans=helper(root->right);
        p.first=1+max(leftans.first,rightans.first);
        p.second=max(leftans.first+rightans.first,max(leftans.second,rightans.second));
        return p;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> p=helper(root);
        return p.second;
    }
};