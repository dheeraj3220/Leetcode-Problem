class Solution {
public:
    void helper(vector<vector<int>>&image,int sr,int sc,int color,int orig){
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]!=orig) return;
        image[sr][sc]=color;
        helper(image,sr+1,sc,color,orig);
        helper(image,sr-1,sc,color,orig);
        helper(image,sr,sc+1,color,orig);
        helper(image,sr,sc-1,color,orig);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
//         queue<pair<int,int>> que;
//         que.push({sr,sc});
//         int prev=image[sr][sc];
//         image[sr][sc]=color;
        
//         while(!que.empty()){
//             int x=que.front().first;
//             int y=que.front().second;
//             que.pop();
//             if(x+1<image.size() && image[x+1][y]==prev){
//                 que.push({x+1,y});
//                 image[x+1][y]=color;
//             }
//             if(x-1>=0 && image[x-1][y]==prev){
//                 que.push({x-1,y});
//                 image[x-1][y]=color;
//             }
//             if(y+1<image[0].size() && image[x][y+1]==prev){
//                 que.push({x,y+1});
//                 image[x][y+1]=color;
//             }
//             if(y-1>=0 && image[x][y-1]==prev){
//                 que.push({x,y-1});
//                 image[x][y-1]=color;
//             }
            
//         }
//         return image;
        int orig=image[sr][sc];
        helper(image,sr,sc,color,orig);
        return image;
    }
};