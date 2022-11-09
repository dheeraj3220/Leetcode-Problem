class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size(); 
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        if(n-1==0 && m-1==0) return 1;
        vector<vector<int>> dist(grid.size(),vector<int>(grid[0].size(),1e9));
        queue<pair<int,pair<int,int>>> que;
        que.push({1,{0,0}});
        dist[0][0]=1;
        int dr[]={1,0,-1,0,1,-1,1,-1};
        int dc[]={0,1,0,-1,1,-1,-1,1};
        while(!que.empty()){
            auto it=que.front();
            int curDist=it.first;
            int x=it.second.first;
            int y=it.second.second;
            que.pop();
            for(int i=0;i<8;i++){
                int newR=x+dr[i];
                int newC=y+dc[i];
                if(newR==n-1 && newC==m-1) return curDist+1;
                if(newR>=0 && newR<n && newC>=0 && newC<m && grid[newR][newC]==0 && curDist+1<dist[newR][newC]){
                    dist[newR][newC]=curDist+1;
                    que.push({{curDist+1},{newR,newC}});
                }
            }
        }
        return -1;
    }
};