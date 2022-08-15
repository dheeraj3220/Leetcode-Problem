class Solution {
public:
    int helper(vector<vector<int>> & matrix,int row,int col,vector<vector<int>>&dp ){
        if(col<0 || col>=matrix.size()) return 1e9;
        if(row==matrix.size()) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int down=matrix[row][col]+helper(matrix,row+1,col,dp);
        int dia1=matrix[row][col]+helper(matrix,row+1,col-1,dp);
        int dia2=matrix[row][col]+helper(matrix,row+1,col+1,dp);
        return dp[row][col]= min(down,min(dia1,dia2));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans=1e9;
         for(int j=0;j<matrix.size();j++){
           ans=min(ans,helper(matrix,0,j,dp));    
        }
        return ans;
    }
};