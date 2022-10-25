class Solution {
public:
     void dfs(vector<vector<int>> & board,vector<vector<int>>& visited,int x,int y){
        
        int m=board.size();
        int n=board[0].size();
        visited[x][y]=1;
        board[x][y]=0;
        if(x+1<m && board[x+1][y]!=0 && !visited[x+1][y])dfs(board,visited,x+1,y);
        if(x-1>=0 && board[x-1][y]!=0 &&  !visited[x-1][y])dfs(board,visited,x-1,y);
        if(y+1<n && board[x][y+1]!=0 && !visited[x][y+1])dfs(board,visited,x,y+1);
        if(y-1>=0 && board[x][y-1]!=0 && !visited[x][y-1])dfs(board,visited,x,y-1);
        board[x][y]=1;
    }
    
    
    int numEnclaves(vector<vector<int>>& board) {
        int count=0;
         int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(board[0][i]==1 && !visited[0][i]) dfs(board,visited,0,i);
            if(board[m-1][i]==1 && !visited[m-1][i]) dfs(board,visited,m-1,i);
        }
        for(int i=0;i<m;i++){
            if(board[i][0]==1 && !visited[i][0]) dfs(board,visited,i,0);
            if(board[i][n-1]==1 && !visited[i][n-1]) dfs(board,visited,i,n-1);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1 && !visited[i][j]) count++;
            }
        }
        return count;
        
    }
};