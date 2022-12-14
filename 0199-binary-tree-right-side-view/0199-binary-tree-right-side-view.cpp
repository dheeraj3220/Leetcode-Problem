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
    vector<int> res;
    int level=0;
    vector<int> rightSideView(TreeNode* root ,int curLevel=0) {
        if(root==NULL ) return res;
        if(curLevel==level){
            res.push_back(root->val);
            level++;
        }
        rightSideView(root->right,curLevel+1);
        rightSideView(root->left,curLevel+1);
        return res;
    }
    
};