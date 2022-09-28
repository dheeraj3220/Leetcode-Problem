class Solution {
public:
    // void bfs(vector<vector<char>>&grid,int i,int j){
    //     queue<pair<int,int>> que;
    //     que.push({i,j});
    //     grid[i][j]='0';
    //     while(!que.empty()){
    //         int x=que.front().first;
    //         int y=que.front().second;
    //         que.pop();
    //         if(x+1<grid.size() && grid[x+1][y]=='1'){ 
    //             que.push({x+1,y});
    //             grid[x+1][y]='0';
    //         }
    //         if(x-1>=0 && grid[x-1][y]=='1'){
    //             que.push({x-1,y});
    //             grid[x-1][y]='0';    
    //         }
    //         if(y+1<grid[0].size() && grid[x][y+1]=='1') {
    //             que.push({x,y+1});
    //             grid[x][y+1]='0';
    //         }
    //         if(y-1>=0 && grid[x][y-1]=='1'){
    //             que.push({x,y-1});
    //             grid[x][y-1]='0';
    //         }
    //     }
    // }
    void dfs(vector<vector<char>>&grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0') return ;
        grid[i][j]='0';
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    // bfs(grid,i,j);
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};