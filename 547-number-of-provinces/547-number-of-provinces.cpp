class Solution {
public:
    void bfs(vector<vector<int>>&isConnected,vector<int>&visited,int node){
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
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(),0);
        int count=0;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                count++;
                bfs(isConnected,visited,i);
            }
        }
        return count;
    }
};