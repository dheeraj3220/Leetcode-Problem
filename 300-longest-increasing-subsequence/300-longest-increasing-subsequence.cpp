class Solution {
public:
    int helper(vector<int>&nums,int index,int prev_index,vector<vector<int>>&dp){
        if(index==nums.size()){
            return 0;
        }
        if(dp[index][prev_index+1]!=-1) return dp[index][prev_index+1];
        
            int length=helper(nums,index+1,prev_index,dp);
        if(prev_index ==-1 || nums[index]>nums[prev_index]) length=max(length,1+helper(nums,index+1,index,dp));
        return dp[index][prev_index+1]=length;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return helper(nums,0,-1,dp);
    }
};