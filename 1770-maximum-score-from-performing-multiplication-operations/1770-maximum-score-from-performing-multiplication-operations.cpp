class Solution {
public:
    int dp[1001][1001];
    int helper(vector<int>& nums, vector<int>& multipliers,int index,int st,int end){
        if(index>=multipliers.size()) return 0;
        if(dp[st][index]!=0x7f7f7f7f) return dp[st][index];
        int cur1=multipliers[index]*nums[st];
        int cur2=multipliers[index]*nums[end];
        return dp[st][index]=max(cur1+helper(nums,multipliers,index+1,st+1,end),cur2+helper(nums,multipliers,index+1,st,end-1));
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        memset(dp,0x7f7f7f7f,sizeof(dp));
       return helper(nums,multipliers,0,0,nums.size()-1);
    }
};
