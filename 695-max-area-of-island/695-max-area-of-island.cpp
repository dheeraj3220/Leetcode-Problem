class Solution {
public:
    void helper(vector<vector<int>>&grid , int row, int col,int x,int y,int & area){
        if(x<0 || y<0 ||x>=row || y>=col || grid[x][y]==0 ) return ;
        area++;
        grid[x][y]=0;
        helper(grid,row,col,x+1,y,area);
        helper(grid,row,col,x-1,y,area);
        helper(grid,row,col,x,y+1,area);
        helper(grid,row,col,x,y-1,area);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    int area=0;
                    helper(grid,row,col,i,j,area);
                    maxarea=max(area,maxarea);
                }
            }
        }
        return maxarea;
        
    }
};