/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val>min(p->val,q->val)&&root->val<max(p->val,q->val)) return root;
        if(root->val==p->val || root->val==q->val) return root;
        TreeNode*leftans=lowestCommonAncestor(root->left,p,q);
            if(leftans) return leftans;
            else
                return lowestCommonAncestor(root->right,p,q);
    }
};