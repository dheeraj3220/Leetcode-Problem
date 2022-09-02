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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        double sum=0,freq=0; 
        if(root==NULL) return res;
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        res.push_back(root->val/1.0);
        while(que.size()){
            if(que.front()==NULL){
                
                double ans=sum/freq;
                que.pop();
                sum=0;
                freq=0;
                if(que.size()==0) break;
                res.push_back(ans);
                que.push(NULL);
            }
            TreeNode*frontt=que.front();
            que.pop();
            if(frontt->left!=NULL){
                que.push(frontt->left);
                sum+=frontt->left->val;
                freq++;
            }
            if(frontt->right!=NULL){
                que.push(frontt->right);
                sum+=frontt->right->val;
                freq++;
            }
        }
      return res;  
    }
};