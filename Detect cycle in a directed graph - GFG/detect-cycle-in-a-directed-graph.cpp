//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private : 
    bool dfs(vector<int> adj[],vector<int>&vis,vector<int>&pathVis,int start){
        vis[start]=1;
        pathVis[start]=1;
        for(auto node : adj[start]){
            if(!vis[node])
            {
                if(dfs(adj,vis,pathVis,node)) return true;
            }
            else if(vis[node] && pathVis[node]) return true;
        }
        pathVis[start]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj,vis,pathVis,i)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends