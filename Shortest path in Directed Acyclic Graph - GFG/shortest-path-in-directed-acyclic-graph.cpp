//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void  dfs(vector<pair<int,int>> adj[],stack<int>&stk,int src,vector<int>&vis){
        vis[src]=1;
        for(auto node : adj[src]){
            if(!vis[node.first]){
                dfs(adj,stk,node.first,vis);
            }
        }
        stk.push(src);
    }
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(auto edge : edges){
            adj[edge[0]].push_back(make_pair(edge[1],edge[2]));
        }
        stack<int> stk;
        vector<int> vis(N,0);
        for(int i=0;i<N;i++)
        if(!vis[i])dfs(adj,stk,i,vis);
        // cout<<stk.size()<<"stk size ";
        vector<int> distance(N,1e9);
        distance[0]=0;
        while(!stk.empty()){
            int cur=stk.top();
            // cout<<cur<<endl;
            stk.pop();
            for(auto dist : adj[cur]){
                // cout<<dist.first <<" fr "<<dist.second<<endl; 
                if(distance[dist.first]>(distance[cur]+dist.second)){
                    distance[dist.first]=distance[cur]+dist.second;
                }
            }
        }
        for(int i=0;i<N;i++) if(distance[i]==1e9) distance[i]=-1;
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends