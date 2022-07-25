class Solution {
public:
    void findCombination(vector<int>candidates,int target,vector<vector<int>>&res,vector<int> ds,int sum,int index){
        if(sum>=target){
            if(sum==target) res.push_back(ds);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            ds.push_back(candidates[i]);
            sum+=candidates[i];
            findCombination(candidates,target,res,ds,sum,i);
            ds.pop_back();
            sum-=candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        int sum=0;
        findCombination(candidates,target,res,ds,sum,0);
        return res;    
    }
};