class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>  adj[n];
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n,0);
        queue<int> que;
        que.push(source);
        vis[source]=1;
        while(!que.empty()){
            int node=que.front();
            que.pop();
            if(node==destination) return true;
            for(auto it : adj[node]){
                if(!vis[it]){
                    que.push(it);
                    vis[it]=1;
                }
            }
        }
        return false;
    }
};