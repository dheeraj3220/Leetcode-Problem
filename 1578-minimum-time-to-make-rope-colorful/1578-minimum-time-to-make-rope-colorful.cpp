class Solution {
public:
    int helper(string &s, vector<int>& need,int index,int prev, vector<vector<int>> &dp){
        if(index==s.size()) return 0;
        if(dp[index][prev+1]!=-2) return dp[index][prev+1];
        int cost=need[index]+helper(s,need,index+1,prev,dp);
        if(prev!=(s[index]-'a')){
            cost=min(cost,helper(s,need,index+1,s[index]-'a',dp));
        }
        return dp[index][prev+1]= cost;
        
    }
    int minCost(string colors, vector<int>& neededTime) {
        vector<vector<int>> dp(colors.size(),vector<int>(26,-2));
        return helper(colors,neededTime,0,-1,dp);    
    }
    
};