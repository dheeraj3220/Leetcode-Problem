//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(vector<int> & visited,vector<int> adj[],int start){
        queue<pair<int,int>> que;
        que.push({start,-1});
        visited[start]=1;
        while(!que.empty()){
            int curNode=que.front().first;
            int prevNode=que.front().second;
            que.pop();
            for(auto node : adj[curNode]){
                if(visited[node]==0){
                    visited[node]=1;
                    que.push({node,curNode});
                }
                else if(node!=prevNode){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfs(visited,adj,i)) return true;
            }
        }
        return false;
         
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends