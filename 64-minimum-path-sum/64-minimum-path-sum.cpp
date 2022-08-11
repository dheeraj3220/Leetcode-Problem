class Solution {
public:
    int n=0,m=0;
    int helper(vector<vector<int>>& grid,int i,int j,vector<vector<int>> &dp){
        if(i==n-1 && j==m-1 ) return grid[i][j];
        if(i>=n || j>=m) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int rightsum=helper(grid,i,j+1,dp);
        int downsum=helper(grid,i+1,j,dp);
        int ans=min(rightsum,downsum)+grid[i][j];
        dp[i][j]=ans;
        return ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(grid,0,0,dp);
    }
};