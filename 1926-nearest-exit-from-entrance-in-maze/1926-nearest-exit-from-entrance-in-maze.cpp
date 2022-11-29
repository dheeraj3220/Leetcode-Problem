class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<int,pair<int,int>>> que;
        que.push({0,{entrance[0],entrance[1]}});
        maze[entrance[0]][entrance[1]]='+';
        while(!que.empty()){
            auto it=que.front();
            int dist=it.first;
            int x=it.second.first;
            int y=it.second.second;
            
            que.pop();
            if((x==0 || y==0 || x==n-1 || y==m-1) && (x!=entrance[0] || y!=entrance[1])) return dist;
            int dr[]={0,-1,0,1};
            int dc[]={-1,0,1,0};
            for(int i=0;i<4;i++){
                int newR=x+dr[i];
                int newC=y+dc[i];
                if(newR>=0 && newC>=0 && newR<n && newC<m && maze[newR][newC]=='.'){
                    maze[newR][newC]='+';
                    que.push({dist+1,{newR,newC}});
                }
            }
            
        }
        return -1;
    }
};