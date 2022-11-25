class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> que;
        int countIsland=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0){
                    que.push({i,j});
                    grid[i][j]=1;
                    bool island=true;
                    while(!que.empty()){
                        int x=que.front().first;
                        int y=que.front().second;
                        // if((x==0 || x==n-1) && (y==0 || y==m-1)) island=false;
                        que.pop();
                        for(int k=0;k<4;k++){
                            int newRow=x+dr[k];
                            int newCol=y+dc[k];
                            if(newRow>=0 && newCol>=0 && newRow<n && newCol<m && grid[newRow][newCol]==0){
                                if((newRow==0 || newRow==n -1 || newCol==0 || newCol==m-1) && grid[newRow][newCol]==0){      
                                island=false;
                            }
                                grid[newRow][newCol]=1;
                                que.push({newRow,newCol});
                            }
                        }
                    }
                    if(island) countIsland++;
                }
            }
        }
        return countIsland;
    }
};