//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    // bool bfs(vector<int> & visited,vector<int> adj[],int start){
    //     queue<pair<int,int>> que;
    //     que.push({start,-1});
    //     visited[start]=1;
    //     while(!que.empty()){
    //         int curNode=que.front().first;
    //         int prevNode=que.front().second;
    //         que.pop();
    //         for(int i=0;i<adj[curNode].size();i++){
    //             if(adj[curNode][i]!=prevNode && visited[adj[curNode][i]]==1)
    //                 return true;
    //             else if(adj[curNode][i]!=prevNode){
    //                 visited[adj[curNode][i]]=1;
    //                 que.push({adj[curNode][i],curNode});
    //             }
    //         }
    //     }
    //     return false;
    // }
    
    ////////////********* DFS *************\\\\\\\\\\\\\\\\\\\\
    
    bool dfs(vector<int> &visited,vector<int> adj[],int start,int prev){
        if(visited[start]==1) return true;
        visited[start]=1;
        for(auto node : adj[start]){
            if(prev!=node && dfs(visited,adj,node,start)) return true;
        }
        return false; 
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(visited,adj,i,-1)==true) return true;
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