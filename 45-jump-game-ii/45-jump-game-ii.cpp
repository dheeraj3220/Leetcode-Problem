class Solution {
public:
    int countJumps(vector<int>&nums,int index,vector<int>&dp){
        if(index>=nums.size()-1) return 0;
        if(dp[index]!=-1) return dp[index];
        int count=100000;
        for(int i=nums[index];i>0;i--){
        count=min(count,1+countJumps(nums,index+i,dp));
        }
        return dp[index]=count;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return countJumps(nums,0,dp);
        
    }
};