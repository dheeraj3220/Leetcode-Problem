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
    void calLeafSequence(TreeNode*root,vector<int>&res){
        if(root==NULL) return ;
        if(!root->left && !root->right){
            res.push_back(root->val);
            return ;
        }
        calLeafSequence(root->left,res);
        calLeafSequence(root->right,res);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1,res2;
        calLeafSequence(root1,res1);
        calLeafSequence(root2,res2);
        return res1==res2;
    }
};