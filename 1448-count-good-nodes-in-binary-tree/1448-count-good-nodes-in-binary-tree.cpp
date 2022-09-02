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
    void helper(TreeNode*root,int x,int & count){
        if(root==NULL) return ;
        if(x<=root->val){
            x=root->val;
            count++;  
        } 
        helper(root->left,x,count);
        helper(root->right,x,count);
    }
    int goodNodes(TreeNode* root,int x=INT_MIN) {
        int count=0;
        helper(root,INT_MIN,count);
        return count;
        
    }
};