class Solution {
public:
    private: 
    bool dfs(vector<vector<int>>& graph,vector<int>&vis,int start,vector<int>&res){
        vis[start]=2;
        for(auto node : graph[start]){
            if(!vis[node]){
                if(dfs(graph,vis,node,res)) return true;
            }
            else if(vis[node]==2) return true;
        }
        res.push_back(start);
        vis[start]=1;
        return false;
    }  
  public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // code here
        vector<int> vis(graph.size(),0);
        vector<int> res;
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
                dfs(graph,vis,i,res);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};