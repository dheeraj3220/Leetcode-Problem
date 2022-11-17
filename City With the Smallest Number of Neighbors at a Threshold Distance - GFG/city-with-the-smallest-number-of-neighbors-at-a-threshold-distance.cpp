//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     vector<vector<int>>  adjMat(n,vector<int>(n,1e9));
            for(auto edge : edges){
                adjMat[edge[0]][edge[1]]=edge[2];
                adjMat[edge[1]][edge[0]]=edge[2];
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j) adjMat[i][j]=0;
                }
            }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adjMat[i][j]=min(adjMat[i][j],adjMat[i][via]+adjMat[via][j]);       
                }
            }
        }
        pair<int,int> res({INT_MIN,INT_MAX}); // {edge,no. of cities}
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(adjMat[i][j]<=distanceThreshold) count++;
            }
            if(count<=res.second){
                res.first=max(res.first,i);
                res.second=count;
            }
        }
        return res.first;
                 }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends