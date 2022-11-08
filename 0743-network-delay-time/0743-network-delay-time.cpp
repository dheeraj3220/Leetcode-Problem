class Solution {
public:
    // int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    //     vector<pair<int,int>> adj[n+1];
    //     for(int i=0;i<times.size();i++){
    //         for(auto time : times){
    //             adj[time[0]].push_back({time[1],time[2]});
    //         }
    //     }
    //     vector<int> distance(n+1,1e9);
    //     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //     pq.push({0,k});
    //     distance[k]=0;
    //     while(!pq.empty()){
    //         int curNode=pq.top().second;
    //         int curDist=pq.top().first;
    //         pq.pop();
    //         for(auto node : adj[curNode]){
    //             if(curDist+node.second < distance[node.first]){
    //                 distance[node.first]=curDist+node.second;
    //                 pq.push({distance[node.first],node.first});
    //             }
    //         }
    //     }
    //     int res=0;
    //     for(int i=1;i<=n;i++){
    //         if(distance[i]>=1e9) return -1;
    //         res=max(res,distance[i]);
    //     }
    //     return res;
    // }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it: times)
        {
            adj[it[0]].push_back({it[2],it[1]});
        }
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto it: adj[node])
            {
                if(dist[node]+it.first<dist[it.second])
                {
                    dist[it.second]=dist[node]+it.first;
                    pq.push({it.first,it.second});
                }
            }
        }
        int ans = *max_element(dist.begin()+1,dist.end());
        return ans==1e9?-1:ans;
    }
};