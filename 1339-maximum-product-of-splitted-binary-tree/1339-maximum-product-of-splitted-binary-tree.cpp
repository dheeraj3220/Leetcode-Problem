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
    // int sumNodes(TreeNode*root){
    //     if(root==NULL) return 0;
    //     return root->val+sumNodes(root->left)+sumNodes(root->right);
    // }
    // int findMaxProd(TreeNode*root,long long & maxProd,int sum){
    //     if(root==NULL) return 0;
    //     int leftans=findMaxProd(root->left,maxProd,sum);
    //     int rightans=findMaxProd(root->right,maxProd,sum);
    //     maxProd=max({maxProd,(sum-leftans)*leftans,(sum-rightans)*rightans});
    //     // result=max({result,(totalTreeSum-sumUnderLeft)*sumUnderLeft,(totalTreeSum-sumUnderRight)*sumUnderRight});
    //     return root->val+rightans+leftans;
    // }
    // int maxProduct(TreeNode* root) {
    //     int sum=sumNodes(root);
    //     long long maxProd=0;
    //     findMaxProd(root,maxProd,sum);
    //     return maxProd;
    // }
       long res = 0, total = 0, sub;
    int maxProduct(TreeNode* root) {
        total = s(root), s(root);
        return res % (int)(1e9 + 7);
    }

    int s(TreeNode* root) {
        if (!root) return 0;
        sub = root->val + s(root->left) + s(root->right);
        res = max(res, sub * (total - sub));
        return sub;
    }
};