class Solution {
public:
    private: 
    // bool dfs(vector<vector<int>>& graph,vector<int>&vis,int start,vector<int>&res){
    //     vis[start]=2;
    //     for(auto node : graph[start]){
    //         if(!vis[node]){
    //             if(dfs(graph,vis,node,res)) return true;
    //         }
    //         else if(vis[node]==2) return true;
    //     }
    //     res.push_back(start);
    //     vis[start]=1;
    //     return false;
    // }  
  public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        // vector<int> vis(graph.size(),0);
        // vector<int> res;
        // for(int i=0;i<graph.size();i++){
        //     if(!vis[i]){
        //         dfs(graph,vis,i,res);
        //     }
        // }
        // sort(res.begin(),res.end());
        // return res;
        int V=adj.size();
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