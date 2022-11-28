class Solution {
public:
    void bfs(vector<vector<int>>& grid,queue<pair<int,int>> que){
        while(!que.empty()){
            int x=que.front().first;
            int y=que.front().second;
            que.pop();
            int dr[]={-1,0,1,0};
            int dc[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int newR=x+dr[i];
                int newC=y+dc[i];
                if(newR>=0 && newC>=0 && newR<grid.size() && newC<grid[0].size() && grid[newR][newC]==1){
                    que.push({newR,newC});
                    grid[newR][newC]=2;
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int done=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    queue<pair<int,int>> que;
                    que.push({i,j});
                    grid[i][j]=2;
                    bfs(grid,que);
                    done=false;
                    break;
                        
                }
            }
            if(!done) break;
        }
        queue<pair<int,pair<int,int>>> que;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    que.push({0,{i,j}});
                }
            }
        }
        while(!que.empty()){
            auto it=que.front();
            int dist=it.first;
            int x=it.second.first;
            int y=it.second.second;
            int dr[]={-1,0,1,0};
            int dc[]={0,-1,0,1};
            que.pop();
            for(int i=0;i<4;i++){
                int newR=x+dr[i];
                int newC=y+dc[i];
                if(newR>=0 && newC>=0 && newR<n && newC<m && grid[newR][newC]!=2){
                    if(grid[newR][newC]==1) return dist;
                    que.push({dist+1,{newR,newC}});
                    grid[newR][newC]=2;
                }
                
            }
        }
        return -1;
    }
    
};