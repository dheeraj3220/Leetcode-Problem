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
    
    int calDia(TreeNode*root,int &dia){
        if(root==NULL) return 0;
        int leftHeight=calDia(root->left,dia);
        int rightHeight=calDia(root->right,dia);
        dia=max(dia,leftHeight+rightHeight);
        return 1+max(leftHeight,rightHeight);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        calDia(root,dia); 
        return dia;
    }
};