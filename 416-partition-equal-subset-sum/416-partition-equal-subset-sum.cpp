class Solution {
public:
    int helper(vector<int> &nums,int index,int k,vector<vector<int>>&dp){
        if(k==0) return 1;
        if(nums.size()==index || k<0 ) return 0;  
        if(dp[index][k]!=-1) return dp[index][k];
        dp[index][k]=helper(nums,index+1,k,dp);
        dp[index][k]=helper(nums,index+1,k-nums[index],dp);
        if(dp[index][k]==1) return dp[index][k];
        return dp[index][k]=helper(nums,index+1,k,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto num:nums) sum+=num;
        vector<vector<int>> dp(nums.size(),vector<int>(sum/2+1,-1));
        return (sum%2)?0:helper(nums,0,sum/2,dp);
    }
};