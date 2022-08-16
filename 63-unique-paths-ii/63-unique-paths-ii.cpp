class Solution {
public:
    int findPaths(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==1 ) 
            return 0;
        if(i==grid.size()-1 && j==grid[0].size()-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int down=findPaths(grid,i+1,j,dp);
        int right=findPaths(grid,i,j+1,dp);
        return dp[i][j]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return findPaths(obstacleGrid,0,0,dp);
    }
};