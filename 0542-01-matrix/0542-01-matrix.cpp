class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> res(m,vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    que.push({{i,j},0});
                    vis[i][j]=1;
                } 
            }
        }
        while(!que.empty()){
            int x=que.front().first.first;
            int y=que.front().first.second;
            int dist=que.front().second;
            res[x][y]=dist;
            que.pop();
            if(x+1<m && vis[x+1][y]==0){
                que.push({{x+1,y},dist+1});
                vis[x+1][y]=1;
            }
            if(x-1>=0 && vis[x-1][y]==0){
                que.push({{x-1,y},dist+1});
                vis[x-1][y]=1;
            }
            if(y+1<n && vis[x][y+1]==0){
                que.push({{x,y+1},dist+1});
                vis[x][y+1]=1;
            }
            if(y-1>=0 && vis[x][y-1]==0){
                que.push({{x,y-1},dist+1});
                vis[x][y-1]=1;
            }
        }
        return res;
        
    }
};