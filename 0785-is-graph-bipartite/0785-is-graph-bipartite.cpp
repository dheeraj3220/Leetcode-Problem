class Solution {
public:
    // bool bfs(vector<vector<int>> &graph,int start,vector<int>&vis){
    //     queue<int> que;
    //     que.push(start);
    //     vis[start]=0;
    //     while(!que.empty()){
    //         int curNode=que.front();
    //         que.pop();
    //         for(auto node : graph[curNode]){
    //             if(vis[node]!=-1 && vis[node]==vis[curNode]) return false;
    //             else if(vis[node]==-1){
    //                 vis[node]=vis[curNode]==0?1:0;
    //                 que.push(node);
    //             }
    //         }
    //     }
    //     return true;
    // }
    bool dfs(vector<vector<int>>&graph,int start,int color,vector<int>&vis){
        vis[start]=color;
        for(auto node : graph[start]){
            if(vis[node]==-1){
                if(dfs(graph,node,!color,vis)==false) return false;
            }
            else if(vis[start]==vis[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                // if(!bfs(graph,i,vis)) return false;
                if(!dfs(graph,i,0,vis)) return false;
            } 
        }
        return true;        
    }
};