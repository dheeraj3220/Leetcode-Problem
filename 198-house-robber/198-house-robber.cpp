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
        // vector<int> dp(nums.size()+1,-1);
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size();i++){
            int notRobbed=prev;
            int robbed=nums[i];
            if(i>1)robbed+=prev2;
            int curi=max(notRobbed,robbed);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
};