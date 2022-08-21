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
// class Solution {
// public:
//     int helper(TreeNode*root,int &maxlen){
//         if (root==NULL) return 0;
//         int right=helper(root->left,maxlen);
//         int left=helper(root->right,maxlen);
//         if(root->right && root->val==root->right->val) {
//             maxlen=max(maxlen,max(1+right,left));
//             right= 1+right;
//         }
//         else if(root->left && root->val==root->left->val) {
//             maxlen=max(maxlen,max(1+left,right));
//             left= 1+left;
//         }
        
//         return 1+max(right,left);   
//     }
//     int longestUnivaluePath(TreeNode* root) {
//         int maxlen=0;
//         helper(root,maxlen);
//         return maxlen-1;
//     }
// };
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int maxlen = 0;
        DFS(root, maxlen);
        return maxlen;
    }
    
    int DFS(TreeNode* root, int& maxlen){
        if(!root) return 0;
        int left = DFS(root->left, maxlen);
        int right = DFS(root->right, maxlen);
        if(!root->left || root->left->val != root->val) left = 0;
        if(!root->right || root->right->val != root->val) right = 0;
        maxlen = max(maxlen, left + right);
        return max(left, right) + 1;
    }
};