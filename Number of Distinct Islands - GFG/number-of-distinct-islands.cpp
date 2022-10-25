//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void helper(vector<vector<int>>& grid,int i,int j,string &s,int n,int m){
        grid[i][j]=0;
        if(i+1<n && grid[i+1][j]!=0) {
            s+='D';
            helper(grid,i+1,j,s,n,m);
        }
        else s+='E';
        if(i-1>=0 && grid[i-1][j]!=0) {
            s+='U';
            helper(grid,i-1,j,s,n,m);
        }
        else s+='E';
        if(j+1<m && grid[i][j+1]!=0) {
            s+='R';
            helper(grid,i,j+1,s,n,m);
        }
        else s+='E';
        if(j-1>=0 && grid[i][j-1]!=0) {
            s+='L';
            helper(grid,i,j-1,s,n,m);
        }
        else s+='E';
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        unordered_set<string> mySet;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    string s="";
                    helper(grid,i,j,s,n,m);
                    mySet.insert(s);
                }
            }
        }
        return mySet.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends