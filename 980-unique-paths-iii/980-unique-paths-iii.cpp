class Solution {
public:
    int findPaths(vector<vector<int>>&grid,int i,int j,int count){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==-1)
            return 0;
        if(grid[i][j]==2 && count==0) return 1;
        if(grid[i][j]==2) return 0;
        grid[i][j]=-1;
        int a=findPaths(grid,i+1,j,count-1);
        int b=findPaths(grid,i,j+1,count-1);
        int c=findPaths(grid,i-1,j,count-1);
        int d=findPaths(grid,i,j-1,count-1);
        grid[i][j]=0;
        return a+b+c+d;
        
        
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=1,row,col;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    row=i;
                    col=j;
                }
                if(grid[i][j]==0) count++;
            }            
        }
        return findPaths(grid,row,col,count);
    }
};



// class Solution {
// public:
//     int  dfs(vector<vector<int>>& grid, int x, int y, int count) {
//         if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) return 0;
        
//         if (grid[x][y] == 2) {
//             if(count==0) return 1; 
//             return 0;
//         }
        
//         grid[x][y] = -1;
        
//         int a=dfs(grid, x+1, y, count-1);
//         int b=dfs(grid, x-1, y, count-1);
//         int c=dfs(grid, x, y+1, count-1);
//         int d=dfs(grid, x, y-1, count-1);
        
//         grid[x][y] = 0;
//         return a+b+c+d;
        
//     }
    
//     int uniquePathsIII(vector<vector<int>>& grid) {
//         int start_x, start_y,empty=1;
//         for (int i = 0; i < grid.size(); i++) {
//             for (int j = 0; j < grid[0].size(); j++) {
//                 if (grid[i][j] == 1) start_x = i, start_y = j;
//                 else if (grid[i][j] == 0) empty++;
//             }
//         }
        
//         return dfs(grid, start_x, start_y, empty);
//     }
// };