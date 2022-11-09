//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        if(source ==destination) return 0;
        vector<vector<int>> dist(grid.size(),vector<int>(grid[0].size(),1e9));
        queue<pair<int,pair<int,int>>> que;
        que.push({0,source});
        dist[source.first][source.second]=0;
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        while(!que.empty()){
            auto it=que.front();
            int curDist=it.first;
            int x=it.second.first;
            int y=it.second.second;
            que.pop();
            for(int i=0;i<4;i++){
                int newR=x+dr[i];
                int newC=y+dc[i];
                if(newR==destination.first && newC==destination.second) return curDist+1;
                if(newR>=0 && newR<grid.size() && newC>=0 && newC<grid[0].size()
                && grid[newR][newC]==1 && curDist+1<dist[newR][newC]){
                    dist[newR][newC]=curDist+1;
                    que.push({{curDist+1},{newR,newC}});
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends