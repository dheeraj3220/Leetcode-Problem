class Solution {
public:
    // int maxRobbedMoney(vector<int> nums,int index,vector<int>&dp){
    //     if(index>=nums.size()-1){
    //         if(nums.size()-1==index) return nums[index];
    //         return 0;
    //     }
    //     if(dp[index]!=-1) return dp[index];
    //     int notRobbed=maxRobbedMoney(nums,index+1,dp);
    //     int robbed=nums[index]+maxRobbedMoney(nums,index+2,dp);
    //     return dp[index]=max(notRobbed,robbed);
    // }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int notRobbed=dp[i-1];
            int robbed=nums[i];
            if(i>1)robbed+=dp[i-2];
            dp[i]=max(notRobbed,robbed);
        }
        return dp[nums.size()-1];
    }
};