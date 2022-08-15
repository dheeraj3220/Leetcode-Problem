// class Solution {
// public:
//      int helper(vector<vector<int>> & matrix,int row,int col,vector<vector<int>>&dp ){
//         if(col<0 || col>=matrix.size()) return 1e9;
//         if(row==matrix.size()) return 0;
//         if(dp[row][col]!=-1) return dp[row][col];
//         dp[row][col]=1e9;
//         for(int i=0;i<matrix.size();i++){
//             if(i!=col)dp[row][col]=min(dp[row][col],matrix[row][col]+helper(matrix,row+1,i,dp));
//         }
//         return dp[row][col];
        
//     }
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         int n=grid.size();
//         if(n==1) return grid[0][0];
//         vector<vector<int>> dp(n,vector<int>(n,-1));
//         int ans=1e9;
//          for(int j=0;j<grid.size();j++){
//            ans=min(ans,helper(grid,0,j,dp));    
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int dp[201][201];
    int f(vector<vector<int>>& arr, int i, int j) {
        if(i == arr.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for(int k = 0; k < arr[0].size(); k++) {
            if(k == j)
                continue;
            int curr = arr[i][j] + f(arr, i + 1, k);
            ans = min(ans, curr);
        }
        return dp[i][j] = ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& arr) {
         int n=arr.size();
        if(n==1) return arr[0][0];
        int ans = INT_MAX;
        memset(dp, -1, sizeof dp);
        for(int j = 0; j < arr[0].size(); j++) {
            ans = min(ans, f(arr, 0, j));
        }
        return ans;
    }
};