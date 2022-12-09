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
    int maxAncestorDiff(TreeNode* root,int maxi=INT_MIN,int mini=INT_MAX) {
        if(root==NULL) return 0;
        maxi=max(root->val,maxi);
        mini=min(root->val,mini);
        return max(abs(maxi-mini),max(maxAncestorDiff(root->left,maxi,mini),maxAncestorDiff(root->right,maxi,mini)));
    }
};