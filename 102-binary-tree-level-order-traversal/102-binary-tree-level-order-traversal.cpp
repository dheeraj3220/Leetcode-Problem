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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        while(!que.empty()){
            if(que.front()==NULL){
                que.pop();
                res.push_back(ans);
                ans.clear();
                if(que.size()==0) break;
                que.push(NULL);
            }
            TreeNode*frontt=que.front();
            que.pop();
            ans.push_back(frontt->val);
            if(frontt->left!=NULL) que.push(frontt->left);
            if(frontt->right!=NULL) que.push(frontt->right);
        }
        return res;
    }
};