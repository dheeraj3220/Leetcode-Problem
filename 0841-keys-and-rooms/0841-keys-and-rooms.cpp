class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> que;
        que.push(0);
        vector<int> vis(rooms.size(),0);
        vis[0]=1;
        while(!que.empty()){
            int curRoom=que.front();
            que.pop();
            for(auto room : rooms[curRoom]){
                if(!vis[room]){
                    que.push(room);
                    vis[room]=1;
                }
            }
        }
        for(auto it : vis) if(!it) return false;
        return true;
    }
};