class Solution {
public:
    int helper(vector<vector<int>>&grid,int i,int j1,int j2,vector<vector<vector<int>>>&dp){
        if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size()) return -10000000;
        if(i==grid.size()-1) {
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=0;
        for(int m1=-1;m1<=1;m1++){
            for(int m2=-1;m2<=1;m2++){
                if(j1==j2) maxi=max(maxi,grid[i][j1]+helper(grid,i+1,j1+m1,j2+m2,dp));
                else maxi=max(maxi,grid[i][j1]+grid[i][j2]+helper(grid,i+1,j1+m1,j2+m2,dp));
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<vector<int>>> dp(row,vector<vector<int>>(col,vector<int>(col,-1)));
        return helper(grid,0,0,col-1,dp); 
    }
};