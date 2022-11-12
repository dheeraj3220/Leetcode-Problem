class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto flight : flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        // {distance,{destination,stops}}
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{src,0}});
        vector<int> distance(n+1,1e9);
        distance[src]=0;
        while(!pq.empty()){
            auto it=pq.top();
            int dist= it.first;
            int curLoc=it.second.first;
            int stops=it.second.second;
            pq.pop();
            for(auto loc : adj[curLoc] ){
                if((dist+loc.second) < distance[loc.first] && (stops+1)<=k+1){
                    distance[loc.first]=dist+loc.second;
                    pq.push ({distance[loc.first],{loc.first,stops+1}});
                    
                }
            }
        }
        return  distance[dst]==1e9?-1:distance[dst];
    }
};