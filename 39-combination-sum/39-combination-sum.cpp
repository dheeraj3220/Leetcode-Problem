class Solution {
public:
    // void findCombination(vector<int>candidates,int target,vector<vector<int>>&res,vector<int> ds,int sum,int index){
    //     if(sum>=target){
    //         if(sum==target) res.push_back(ds);
    //         return;
    //     }
    //     for(int i=index;i<candidates.size();i++){
    //         ds.push_back(candidates[i]);
    //         sum+=candidates[i];
    //         findCombination(candidates,target,res,ds,sum,i);
    //         ds.pop_back();
    //         sum-=candidates[i];
    //     }
    // }
    void calculateSum(vector<int> nums,vector<vector<int>>&res,vector<int> ds,int k,int &sum,int index){
    if(index==nums.size() || sum>=k){
        if(sum==k) res.push_back(ds);
        return;
    }
    sum+=nums[index];
    ds.push_back(nums[index]);
    calculateSum(nums,res,ds,k,sum,index);
    sum-=nums[index];
    ds.pop_back();
    calculateSum(nums,res,ds,k,sum,index+1);
        
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        int sum=0;
        calculateSum(candidates,res,ds,target,sum,0);
        return res;    
    }
};