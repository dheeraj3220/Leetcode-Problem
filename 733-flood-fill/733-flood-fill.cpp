class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        queue<pair<int,int>> que;
        que.push({sr,sc});
        int prev=image[sr][sc];
        image[sr][sc]=color;
        
        while(!que.empty()){
            int x=que.front().first;
            int y=que.front().second;
            que.pop();
            if(x+1<image.size() && image[x+1][y]==prev){
                que.push({x+1,y});
                image[x+1][y]=color;
            }
            if(x-1>=0 && image[x-1][y]==prev){
                que.push({x-1,y});
                image[x-1][y]=color;
            }
            if(y+1<image[0].size() && image[x][y+1]==prev){
                que.push({x,y+1});
                image[x][y+1]=color;
            }
            if(y-1>=0 && image[x][y-1]==prev){
                que.push({x,y-1});
                image[x][y-1]=color;
            }
            
        }
        return image;
    }
};