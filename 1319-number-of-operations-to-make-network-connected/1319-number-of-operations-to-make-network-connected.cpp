class Solution {
public:
    void dfs(vector<int>&vis,vector<int> adj[],int start){
        vis[start]=1;
        for(auto it : adj[start]){
            if(!vis[it]){
                dfs(vis,adj,it);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
       vector<int> adj[n];
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
       vector<int> vis(n,0);
       int wireNum=connections.size();
       if(wireNum<n-1) return -1;
        int count=0;
       for(int i=0;i<n;i++){
           if(!vis[i]){
               dfs(vis,adj,i);
               count++;
           }
       }
        return count-1;
    }
};