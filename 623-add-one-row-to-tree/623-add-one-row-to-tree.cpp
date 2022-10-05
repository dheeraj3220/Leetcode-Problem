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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL || depth ==0) return root;
        if(depth==1){
            TreeNode*newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        if(depth==2){
                TreeNode*newleft=new TreeNode(val);
                newleft->left=root->left;
                root->left=newleft;
                TreeNode*newright=new TreeNode(val);
                newright->right=root->right;
                root->right=newright;
                return root;
        }
        addOneRow(root->left,val,depth-1);
        addOneRow(root->right,val,depth-1);
        return root;
    }
};