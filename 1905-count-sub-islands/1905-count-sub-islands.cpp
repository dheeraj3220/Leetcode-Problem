class Solution {
public:
//     void bfs(int i , int j , vector<vector<int>>&grid1  ,queue<pair<int,int>> &q , int &ans, vector<vector<int>>&grid2){
//         q.push({i,j});
//         grid2[i][j]=0;
//         bool isIsland=true;
//         if(grid1[i][j]!=1)isIsland=false;
//         while(!q.empty()){
//             int row = q.front().first;
//             int col =q.front().second;
           
//             q.pop();
//             int delrow[]={0,-1,0,+1};
//             int delcol[]={-1,0,+1,0};
//             for(int i =0;i<4;i++){
//                 int nrow=row+delrow[i];
//                 int ncol= col+delcol[i];
//                 if(nrow>=0&&ncol>=0&&ncol<grid1[0].size()&& nrow<grid1.size()&&grid2[nrow][ncol]==1){
//                     if(grid1[nrow][ncol]!=1)isIsland=false;
//                   grid2[nrow][ncol]=0;
//                     q.push({nrow,ncol});
                    
//                 }
//             }
//         }
//         if(isIsland==true)ans++;
        
//     }
 
//     int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
//         queue<pair<int,int>> q;
        
//         int ans=0;
        
//         for(int i =0;i<grid1.size();i++){
//             for(int j =0;j<grid1[0].size();j++){
//                 if(grid2[i][j]==1){
//                     bfs(i,j,grid1,q,ans,grid2);
//                 }
                
//         }
//     }
//         return ans;
//     }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        int count=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
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
                        int dr[]={-1,0,1,0};
                        int dc[]={0,-1,0,1};
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