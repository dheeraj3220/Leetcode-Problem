class Solution {
public:
    void dfs(vector<vector<int>> graph ,vector<int> vis,int curNode,
            vector<vector<int>>&res,vector<int> path){
        vis[curNode]=1;
        if(curNode==(graph.size()-1)){
            res.push_back(path);
            return ;
        }
        for(auto it : graph[curNode]){
            if(!vis[it]){
                path.push_back(it);
                dfs(graph,vis,it,res,path);
                path.pop_back();
            }
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        vector<int> vis(graph.size(),0);
        path.push_back(0);
        dfs(graph,vis,0,res,path);
        return res;
    }
};