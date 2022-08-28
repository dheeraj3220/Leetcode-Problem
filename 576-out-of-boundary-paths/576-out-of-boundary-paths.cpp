class Solution {
public:
    int mod=1000000007;
    int dp[110][110][110];
    int helper(int m, int n, int maxMove, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n) {
            return 1;
        }
        if(maxMove<=0) return 0;
        if(dp[i][j][maxMove]!=-1) return dp[i][j][maxMove];
        int a=helper(m,n,maxMove-1,i+1,j)%mod;
        int b=helper(m,n,maxMove-1,i-1,j)%mod;
        int c=helper(m,n,maxMove-1,i,j+1)%mod;
        int d=helper(m,n,maxMove-1,i,j-1)%mod;
        return dp[i][j][maxMove]=((((a+b)%mod+c)%mod+d))%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return helper(m,n,maxMove,startRow,startColumn);
    }
};