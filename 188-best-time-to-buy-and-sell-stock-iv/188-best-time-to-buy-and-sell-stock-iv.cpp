class Solution {
public:
    int helper(vector<int> & prices,int index,int k,int dec ,vector<vector<vector<int>>>&dp){
        if( k==0 || index==prices.size()) return 0;
        if(dp[index][k][dec]!=-1) return dp[index][k][dec];
        int buy=0;
        int sell=0;
        if(dec==1)  buy=helper(prices,index+1,k,0,dp)-prices[index];
        if(dec==0)  sell=prices[index]+ helper(prices,index+1,k-1,1,dp);
        int proceed=helper(prices,index+1,k,dec,dp);
        return dp[index][k][dec]=max(buy,max(sell,proceed));
        
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(1001,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return helper(prices,0,k,1,dp);
    }
};