class Solution {
public:
    int helper(vector<int> cost,int index,vector<int>&dp){
        if(index>=cost.size()){
            return 0;
        }
        if(dp[index]!=-1) return dp[index];
        int cost1=cost[index]+helper(cost,index+1,dp);
        int cost2=cost[index]+helper(cost,index+2,dp);
        return dp[index]= min(cost1,cost2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return min(helper(cost,0,dp),helper(cost,1,dp));
    }
};