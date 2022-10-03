class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            int t=pq.top().first;
            vector<int> ans;
            while(ans.size()<t){
                ans.push_back(pq.top().second);
                pq.pop();
            }
            res.push_back(ans);
        }
        return res;
    }
};