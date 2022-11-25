class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> que;
        int maxi=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]!=1){
                    que.push({i,j});
                    vis[i][j]=1;
                    int curMax=0;
                    while(!que.empty()){
                        int x=que.front().first;
                        int y=que.front().second;
                        que.pop();
                        curMax++;
                        for(int i=0;i<4;i++){
                            int newRow=x+dr[i];
                            int newCol=y+dc[i];
                            if(newRow>=0 && newCol>=0 && newRow<n && newCol<m && vis[newRow][newCol]!=1 && grid[newRow][newCol]==1){
                                vis[newRow][newCol]=1;
                                que.push({newRow,newCol});
                            }
                        }
                        
                    }
                    maxi=max(curMax,maxi);
                }
            }
        }
        return maxi;
    }
};