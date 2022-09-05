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
       void helper(TreeNode*root,int order,int level,priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> >&pq){
        if(root==NULL) return ;
        pair<int,pair<int,int>> p;
        p.first=order;
        p.second.first=level;
        p.second.second=root->val;
        pq.push(p);
        helper(root->left,order-1,level+1,pq);
        helper(root->right,order+1,level+1,pq);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        helper(root,0,0,pq);
        vector<int> temp;
        int prev=0;
        while(!pq.empty()){
            if(temp.empty() || prev==pq.top().first){
                int t=pq.top().second.second;
                temp.push_back(t);
                prev=pq.top().first;
                pq.pop();
            }
            else{
                res.push_back(temp);
                temp.clear();
            }
        }
        res.push_back(temp);
        return res;
        
    }
};