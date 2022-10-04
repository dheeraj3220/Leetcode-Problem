class Solution {
public:
    int dp[1001][1001];
    int suffix[1001];

    void findSuffixSum(string& floor) {
        int n = floor.size();
        
        suffix[n - 1] = (floor[n - 1] == '1');
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + (floor[i] == '1');
        }
    }
    
    int solve(string& floor, int numCarpets, int carpetLen, int pos, int used) {
        if (pos >= floor.size()) {
            return 0;
        } else if (used == numCarpets) {
            return suffix[pos];
        }
        
        if (dp[pos][used] != -1) {
            return dp[pos][used];
        }

        return dp[pos][used] = min(solve(floor, numCarpets, carpetLen, pos + carpetLen, used + 1),
                      (floor[pos] == '1') + solve(floor, numCarpets, carpetLen, pos + 1, used));
    }
    
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        memset(dp, -1, sizeof(dp));
        findSuffixSum(floor);
        
        return solve(floor, numCarpets, carpetLen, 0, 0);
    }
};

















// class Solution {
// public:
//     int suff[1001];
//     void calSuff(string &s){
//         int n=s.size();
//         suff[n-1]= (s[n-1]=='1');
//         for(int i=n-2;i>=0;i--){
//             suff[i]=(s[i]=='1')+s[i+1];
//         }
//     }
//     int minimizeWhite(string &s,int cc,int clen,int index,vector<vector<int>>&dp,int ccl){
//         if(index>=s.size()) return 0;
//         if(cc==ccl) return suff[index];
//         if(dp[index][ccl]!=-1) return dp[index][ccl];
//         int white=(s[index]=='1') + minimizeWhite(s,cc,clen,index+1,dp,ccl);
//             white=min(white,minimizeWhite(s,cc,clen,index+clen,dp,ccl+1));
//         return dp[index][ccl]=white;
        
//     }
//     int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
//         vector<vector<int>> dp(1001,vector<int>(1001,-1));
//         if(floor.size()<=(numCarpets*carpetLen) && carpetLen<=floor.size()) return 0;
//         calSuff(floor);
//       return  minimizeWhite(floor,numCarpets,carpetLen,0,dp,0);  
//     }
// };