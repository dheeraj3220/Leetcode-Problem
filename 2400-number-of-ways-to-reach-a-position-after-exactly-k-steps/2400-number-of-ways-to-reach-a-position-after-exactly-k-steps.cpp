class Solution {
public:
    int helper(int st,int end,int k,vector<vector<int>>&dp){
        if(k<=0){
            if(st==end){
              return 1;
            } 
            return 0;
        }
        if(dp[st+1000][k]!=-1) return dp[st+1000][k];
        return dp[st+1000][k]=(helper(st-1,end,k-1,dp)+helper(st+1,end,k-1,dp))%1000000007;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3001,vector<int>(k+1,-1));
        return helper(startPos,endPos,k,dp);
        
    }
};