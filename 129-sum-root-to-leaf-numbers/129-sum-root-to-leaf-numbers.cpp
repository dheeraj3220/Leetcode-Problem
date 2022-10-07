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
    void calSum(TreeNode*root,int curSum,int &totalSum){
        if(root->left==NULL && root->right==NULL){
            curSum*=10;
            curSum+=root->val;
            totalSum+=curSum;
            return;
        } 
        curSum*=10;
        curSum+=root->val;
        if(root->left)calSum(root->left,curSum,totalSum);
        if(root->right)calSum(root->right,curSum,totalSum);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        int curSum=0;
        int totalSum=0;
        calSum(root,curSum,totalSum);
        return totalSum;
    }
};