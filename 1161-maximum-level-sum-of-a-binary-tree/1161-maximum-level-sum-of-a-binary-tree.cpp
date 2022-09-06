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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL) return 0;
        int maxSumLevel=1,level=2,sum=0,maxSum=root->val;
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        maxSum=root->val;
        while(!que.empty()){
            if(que.front()==NULL){
                que.pop();
                if(maxSum<sum){
                    maxSum=sum;
                    maxSumLevel=level;
                }
                level++;
                sum=INT_MIN;
                if(que.size()==0) break;
                que.push(NULL);
            }
            TreeNode*frontt=que.front();
            que.pop();
            if(frontt->left) {
                if(sum==INT_MIN) sum=0;
                que.push(frontt->left);
                sum+=frontt->left->val;
            }
            if(frontt->right) {
                if(sum==INT_MIN) sum=0;
                que.push(frontt->right);
                sum+=frontt->right->val;
            }
        }
        return maxSumLevel;
    }
};