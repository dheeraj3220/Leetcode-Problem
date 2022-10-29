//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private: 
    // bool dfs(vector<int> adj[],vector<int>&vis,int start,vector<int>&res){
    //     vis[start]=2;
    //     for(auto node : adj[start]){
    //         if(!vis[node]){
    //             if(dfs(adj,vis,node,res)) return true;
    //         }
    //         else if(vis[node]==2) return true;
    //     }
    //     res.push_back(start);
    //     vis[start]=1;
    //     return false;
    // }  
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        // vector<int> vis(V,0);
        vector<int> newAdj[V];
        for(int i=0;i<V;i++){
            for(auto node : adj[i]){
                newAdj[node].push_back(i);
            }
        }
        vector<int> inDegree(V,0);
        for(int i=0;i<V;i++){
            for(auto node: newAdj[i]){
                inDegree[node]++;
            }
        }
        queue<int> que;
        vector<int> res;
        for(int i=0;i<V;i++) if(inDegree[i]==0) que.push(i);
        while(!que.empty()){
            int curNode=que.front();
            res.push_back(curNode);
            que.pop();
            for(auto node : newAdj[curNode]){
                inDegree[node]--;
                if(inDegree[node]==0) que.push(node);
            }
        }
        // for(int i=0;i<V;i++){
        //     if(!vis[i]){
        //         dfs(adj,vis,i,res);
        //     }
        // }
        sort(res.begin(),res.end());
        return res;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends