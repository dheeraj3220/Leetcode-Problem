class Solution {
public:
     int helper(vector<vector<int>> & matrix,int row,int col,vector<vector<int>>&dp ){
        if(col<0 || col>=matrix.size()) return 1e9;
        if(row==matrix.size()) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        dp[row][col]=1e9;
        for(int i=0;i<matrix.size();i++){
            if(i!=col)dp[row][col]=min(dp[row][col],matrix[row][col]+helper(matrix,row+1,i,dp));
        }
        return dp[row][col];
        
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1) return grid[0][0];
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans=1e9;
         for(int j=0;j<grid.size();j++){
           ans=min(ans,helper(grid,0,j,dp));    
        }
        return ans;
    }
};