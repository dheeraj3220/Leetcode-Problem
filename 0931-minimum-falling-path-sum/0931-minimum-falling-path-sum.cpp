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
//     int helper ( int i , int j , vector<vector<int>>& matrix){
//         if(j>=matrix[0].size()||j<0)return 1e9;
//         if(i==0) return matrix[i][j];
//         int up = matrix[i][j]+ helper(i-1,j,matrix);
//         int ld=matrix[i][j] + helper(i-1,j-1,matrix);
//         int rd=matrix[i][j]+helper(i-1,j+1,matrix);
//         return min(up,min(ld,rd));
       
//     }
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n =matrix.size();
//         int m = matrix[0].size();
//         int mini =1e9;
//         for(int j=0;j<m;j++){
//             mini = min(mini,helper(n-1,j,matrix));
//         }
//         return mini;
//     }
};



