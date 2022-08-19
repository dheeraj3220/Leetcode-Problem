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
    bool isValidBST(TreeNode* root,long ll=LONG_MIN ,long rl=LONG_MAX) {
        if(root==NULL)
            return true;
        if(root->val<=ll || root->val>=rl) return false;
        return (isValidBST(root->left,ll,root->val) && isValidBST(root->right,root->val,rl));
    
        
    }
};