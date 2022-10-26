//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
// 	void dfs(vector<int> adj[],vector<int>&vis,vector<int>&res,int start){
// 	    vis[start]=1;
// 	    for(auto node : adj[start]){
// 	        if(!vis[node]) dfs(adj,vis,res,node);
// 	    }
// 	    res.push_back(start);
// 	    return ;
// 	}

////////////KAhN's Algorithm
    void bfs(vector<int> adj[],vector<int>&vis,vector<int>&res,int start,vector<int>& inDegree){
        queue<int> que;
        for(int i=0;i<vis.size();i++){
            if(!vis[i] && inDegree[i]==0){ 
                que.push(i);
                vis[i]=1;
                
            }
        }
        while(!que.empty()){
            int curNode=que.front();
            que.pop();
            res.push_back(curNode);
            for(auto node : adj[curNode]){
                inDegree[node]--;
                if(inDegree[node]==0){
                    que.push(node);
                    vis[node]=1;
                }
            }
        }

    }
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V,0);
	    vector<int> res;
	    vector<int> inDegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto node : adj[i]){
	            inDegree[node]++;
	        }
	    }
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	           // dfs(adj,vis,res,i);
	           bfs(adj,vis,res,i,inDegree);
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends