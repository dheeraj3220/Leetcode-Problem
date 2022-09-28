class Solution {
public:
    
        /*************Breadth First Search***************/
    
    
    /* void bfs(vector<vector<int>>&isConnected,vector<int>&visited,int node){
        queue<int> que;
        que.push(node);
        visited[node]=1;
        while(!que.empty()){
            int num=que.front();
            que.pop();
            for(int i=0;i<isConnected.size();i++){
                if(isConnected[num][i]==1 && !visited[i]){
                    que.push(i);
                    visited[i]=1;
                }
            }
        }
    } */
    
     /***************Depth First Search*****************/
    void dfs(vector<vector<int>>&isConnected,vector<int>&visited,int node){
        visited[node]=1;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[node][i]==1 && !visited[i]) dfs(isConnected,visited,i);
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(),0);
        int count=0;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                count++;
                // bfs(isConnected,visited,i);
                dfs(isConnected,visited,i);
            }
        }
        return count;
    }
};