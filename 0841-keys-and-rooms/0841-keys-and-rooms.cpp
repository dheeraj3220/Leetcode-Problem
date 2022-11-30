// class Solution {
// public:
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         vector<int> inDegree(rooms.size(),0);
//         for(int j=0;j<rooms.size();j++){
//             for(int i=0;i<rooms[j].size();i++){
//                if(rooms[j][i]!=j) inDegree[rooms[j][i]]++;
//             }
//         }
//         int count=0;
//         queue<int >  que;
//         for(int i=0;i<rooms.size();i++){ 
//             if(inDegree[i]==0){
//                 que.push(i);
//                 count++;
//             }
//         }
//         while(!que.empty()){
//             int curNode=que.front();
//             que.pop();
//             for(auto node : rooms[curNode]){
//                 inDegree[node]--;
//                 if(inDegree[node]==0) que.push(node);
//                 count++;
//             }
//         }
//         return count==rooms.size();
//     }
// };
class Solution {
public:
    void dfs(map<int,vector<int>>& mp,int node,vector<int>& visi,stack<int>& st){
        visi[node] = 1;
        for(auto nbr:mp[node]){
            if(!visi[nbr]){
                dfs(mp,nbr,visi,st);
            }
        }
        st.push(node);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        map<int,vector<int>> mp;
        for(int i = 0;i < rooms.size();i++){
            if(rooms[i].size() == 0){
                continue;
            }
            for(auto J:rooms[i]){
                mp[i].push_back(J);
            }
        }
        stack<int> topo;
        int n = rooms.size();
        vector<int> visited(n,0);
        dfs(mp,0,visited,topo);
        return topo.size() == rooms.size();
    }
};