class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int totalOranges=0;
        int rottenOranges=0;
        int minutes=0;
        queue<pair<int,int>> que;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2) {
                    rottenOranges++;
                    que.push({i,j});   
                }
                if(grid[i][j]!=0) totalOranges++;
            }
        }
        if(totalOranges==0 || totalOranges==rottenOranges) return 0;
        rottenOranges=0;
        
        while(!que.empty()){
            int queSize=que.size();
            for(int i=0;i<queSize;i++){
                pair curOrange=que.front();
                que.pop();
                int x=curOrange.first;
                int y=curOrange.second;
                if(x+1<grid.size() && grid[x+1][y]==1){
                  que.push({x+1,y});
                  grid[x+1][y]=2;  
                } 
                if(x-1>=0 && grid[x-1][y]==1) {
                 que.push({x-1,y});
                 grid[x-1][y]=2;  
                }
                if(y+1<grid[0].size() && grid[x][y+1]==1) { 
                   que.push({x,y+1});
                   grid[x][y+1]=2;  
                }
                if(y-1>=0 && grid[x][y-1]==1) 
                {
                    que.push({x,y-1});
                    grid[x][y-1]=2;  
                }
                rottenOranges++;
                
            }
            minutes++;
        }
        if(rottenOranges==totalOranges) return minutes-1;
        else
            return -1;
    }
};