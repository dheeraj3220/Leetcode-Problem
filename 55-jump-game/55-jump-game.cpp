class Solution {
public:
    int helper(vector<int> &nums,vector<int>& dp,int index){
        if(index>=nums.size()-1)
            return 1;
        if(nums[index]==0 && index!=nums.size()-1) return 0;
        if(dp[index]!=-1) return dp[index];
        dp[index]=0;
        for(int i=nums[index];i>=1;i--){
            dp[index]=dp[index] || helper(nums,dp,index+i);
            if(dp[index]) return dp[index];
        }
        return dp[index];
    }
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        vector<int> dp(nums.size()+1,-1);
        return helper(nums,dp,0);
    }
    
};