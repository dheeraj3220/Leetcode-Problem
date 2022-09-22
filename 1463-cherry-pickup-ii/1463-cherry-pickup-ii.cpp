class Solution {
public:
    int helper(vector<vector<int>>& grid,int row,int col1,int col2 ,vector<vector<vector<int>>>& dp){
        if(col1<0 || col1>=grid[0].size()||col2<0 || col2>=grid[0].size()) return -10000000;
        if(row==grid.size()) return 0;
        if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];
        int cherry=0;
        for(int m1=-1;m1<=1;m1++){
            for(int m2=-1;m2<=1;m2++){
               if(col2==col1) cherry=max(cherry,grid[row][col1]+helper(grid,row+1,col1+m1,col2+m2,dp));
                else cherry=max(cherry,grid[row][col1]+grid[row][col2]+helper(grid,row+1,col1+m1,col2+m2,dp));
            }
        }
        return dp[row][col1][col2]=cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return helper(grid,0,0,m-1,dp);
    }
};