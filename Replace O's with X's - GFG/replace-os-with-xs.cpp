//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void dfs(vector<vector<char>> & board,vector<vector<int>>& visited,int x,int y){
        
        int m=board.size();
        int n=board[0].size();
        visited[x][y]=1;
        board[x][y]='X';
        if(x+1<m && board[x+1][y]!='X' && !visited[x+1][y])dfs(board,visited,x+1,y);
        if(x-1>=0 && board[x-1][y]!='X' &&  !visited[x-1][y])dfs(board,visited,x-1,y);
        if(y+1<n && board[x][y+1]!='X' && !visited[x][y+1])dfs(board,visited,x,y+1);
        if(y-1>=0 && board[x][y-1]!='X' && !visited[x][y-1])dfs(board,visited,x,y-1);
        board[x][y]='O';
    }
    vector<vector<char>> fill(int N, int M, vector<vector<char>> board)
    {
        // code here
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(board[0][i]=='O' && !visited[0][i]) dfs(board,visited,0,i);
            if(board[m-1][i]=='O' && !visited[m-1][i]) dfs(board,visited,m-1,i);
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' && !visited[i][0]) dfs(board,visited,i,0);
            if(board[i][n-1]=='O' && !visited[i][n-1]) dfs(board,visited,i,n-1);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !visited[i][j]) board[i][j]='X';
            }
        }
        return board;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends