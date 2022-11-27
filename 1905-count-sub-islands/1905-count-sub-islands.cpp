class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        int count=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                queue<pair<int,int>> que;
                if(grid2[i][j]==1){
                    queue<pair<int,int>> que;
                    bool island=true;
                    que.push({i,j});
                    if(grid1[i][j]!=1) island=false;
                    grid2[i][j]=0;
                    while(!que.empty()){
                        auto it=que.front();
                        int x=it.first;
                        int y=it.second;
                        que.pop();
                        for(int i=0;i<4;i++){
                            int newR=x+dr[i];
                            int newC=y+dc[i];
                            if(newC>=0 && newR>=0 && newR<n && newC<m && grid2[newR][newC]==1){
                                if(grid1[newR][newC]!=1) island=false;
                                que.push({newR,newC});
                                grid2[newR][newC]=0;
                            }
                        }
                    }
                    if(island) count++;
                }
            }
        }
        return count;
    }
};