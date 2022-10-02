class Solution {
public:
    int maxSum(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        int sum=0;
        int maxSum=0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                 sum=a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+1]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];
                maxSum=max(sum,maxSum);
            }
            
        }
        return maxSum;
    }
};