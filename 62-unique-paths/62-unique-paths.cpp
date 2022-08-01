class Solution {
public:
    int helper(int x,int y,int m,int n,vector<vector<int>>& dp){
        if(x==m-1 && y==n-1) return 1;
        if(x>=m || y>=n) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        int dns=helper(x+1,y,m,n,dp);
        int rns=helper(x,y+1,m,n,dp);
        dp[x][y]=dns+rns;
        return dns+rns;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
       return  helper(0,0,m,n,dp);
        
    }
};