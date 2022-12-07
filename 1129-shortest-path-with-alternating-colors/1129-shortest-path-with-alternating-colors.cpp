class Solution {
    vector<vector<int>> redNodes, blueNodes;
    vector<vector<int>> moves;
    
    void dfs(int i, int move, int flag){
        if(move >= moves[i][flag])
            return;
            
        moves[i][flag] = min(move, moves[i][flag]);
        
        if(flag == 0)
            for(auto j : redNodes[i])
                dfs(j, move+1, 1);
        if(flag == 1)
            for(auto j : blueNodes[i])
                dfs(j, move+1, 0);
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        redNodes.resize(n);
        blueNodes.resize(n);
        moves.resize(n, vector<int>(2,1e3));
        
        for(auto edge : redEdges)
            redNodes[edge[0]].push_back(edge[1]);
        for(auto edge : blueEdges)
            blueNodes[edge[0]].push_back(edge[1]);
        
        dfs(0, 0, 0);   // Flag : [0] -> red, [1] -> blue
        dfs(0, 0, 1);
        
        vector<int> ans(n);
        for(int i = 0; i<n; i++){
            int move = min(moves[i][0], moves[i][1]);
            
            if(move == 1e3)
                ans[i] = -1;
            else
                ans[i] = move;
        }
        
        return ans;
    }
};



// class Solution {
// public:
//     vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
//         // COLORS - > RED-0 ,BLUE-1
//         vector<pair<int,int>> adj[n];
//         for(auto red : redEdges) adj[red[0]].push_back({red[1],0});
//         for(auto blue :blueEdges) adj[blue[0]].push_back({blue[1],1});
//         vector<int> res(n,-1);
//         queue<pair<int,pair<int,int>>> que;
//         que.push({0,{0,-1}});
//         vector<int> red(n,0);
//         vector<int> blue(n,0);
//         vector<int> vis(n,0);
//         vis[0]=1;
//         res[0]=0;
//         while(!que.empty()){
//             auto it=que.front();
//             int curNode=it.first;
//             int dist=it.second.first;
//             int prevColor=it.second.second;
//             que.pop();
//             if(prevColor==0) {
//                 if(red[curNode]==0) red[curNode]=1;
//                 else vis[curNode]=1;
//             }
//             else if(prevColor==1){
//                 if(blue[curNode]==0) blue[curNode]=1;
//                 else vis[curNode]=1;
//             }
//            if(red[curNode]==1 && blue[curNode]==1) vis[curNode]=1;
//             if(res[curNode]==-1) res[curNode]=dist;
//             else res[curNode]=min(res[curNode],dist);
//             for(auto node : adj[curNode]){
//                 if(!vis[node.first] && (curNode==0 || node.second!=prevColor)){
//                     que.push({node.first,{dist+1,node.second}});
//                 }
//             }
//         }
//         return res;
//     }
// };