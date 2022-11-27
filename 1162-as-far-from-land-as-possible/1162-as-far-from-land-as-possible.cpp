class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int farestLand=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> que;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    vis[i][j]=1;
                    que.push({0,{i,j}});
                }
            }
        }
        while(!que.empty()){
            auto it=que.front();
            int dist=it.first;
            int x=it.second.first;
            int y=it.second.second;
            if(grid[x][y]==0) farestLand=max(farestLand,dist);
            que.pop();
            int dr[]={1,0,-1,0};
            int dc[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int newR=x+dr[i];
                int newC=y+dc[i];
                if(newC>=0 && newR>=0 && newR<n && newC<m && vis[newR][newC]!=1){
                    vis[newR][newC]=1;
                    que.push({dist+1,{newR,newC}});
                    
                }
            }
        }
        if(farestLand==0) return -1;
        return farestLand;
    }
};