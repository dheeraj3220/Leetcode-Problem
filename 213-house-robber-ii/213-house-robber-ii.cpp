class Solution {
public:
    int helper(vector<int>nums,int index,int last,vector<int>&dp){
        if(index>=last){
            return 0;
        }
        if(dp[index]!=-1) return dp[index];
        int rob=nums[index]+helper(nums,index+2,last,dp);
        int notRob=helper(nums,index+1,last,dp);
        return dp[index]=max(rob,notRob);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp1(nums.size()+1,-1);
        vector<int> dp2(nums.size()+1,-1);
        return max(helper(nums,0,nums.size()-1,dp1),helper(nums,1,nums.size(),dp2));
        
    }
};