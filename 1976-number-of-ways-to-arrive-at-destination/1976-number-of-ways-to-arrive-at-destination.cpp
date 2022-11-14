// class Solution {
// public:
//     int countPaths(int n, vector<vector<int>>& roads) {
//         vector<pair<int,int>> adj[n];
//         for(auto road : roads){
//             adj[road[0]].push_back({road[1],road[2]});
//             adj[road[1]].push_back({road[0],road[2]});
//         }
//         priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
//         vector<long long> time(n,1e9);
//         vector<long long> ways(n,0);
//         ways[0]=1;
//         pq.push({0,0});
//         time[0]=0;
//         while(!pq.empty()){
//             auto it=pq.top();
//             long long curTime=it.first;
//             long long curCity=it.second;
//             pq.pop();
//             for(auto iter : adj[curCity]){
//                 long long adjCity=iter.first;
//                 long long adjCityTime=iter.second;       
//                 if(curTime+adjCityTime<time[adjCity]){
//                     time[adjCity]=curTime+adjCityTime;
//                     ways[adjCity]=ways[curCity];
//                     pq.push({time[adjCity],adjCity});
//                 }      
//                 else if(curTime+adjCityTime==time[adjCity]) 
//                     ways[adjCity]=(ways[adjCity]%1000000007+ways[curCity]%1000000007)%1000000007;
//             }
//         }
//         return ways[n-1]%1000000007;
//     }
// };
#define ll long long
class Solution {
public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll,ll>> adj[n];
       for(auto it:roads){
           adj[it[0]].push_back({it[1],it[2]});
           adj[it[1]].push_back({it[0],it[2]});
       }
       
       priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
       vector<ll> dist(n,LONG_MAX), ways(n,0);
       dist[0] = 0;
       ways[0] = 1;
       
       pq.push({0,0});
       
       while(!pq.empty()){
           ll dis = pq.top().first;
           ll node = pq.top().second;
           pq.pop();
           
           for(auto it: adj[node]){
               ll adjNode = it.first;
               ll edW = it.second;
               //this is the first time I am coming
               //with the short distance
               if(dis + edW < dist[adjNode]){
                   dist[adjNode] = dis + edW;
                   pq.push({dis + edW,adjNode});
                   ways[adjNode] = ways[node];
               }
               else if(dis +edW == dist[adjNode]){
                   ways[adjNode] = (ways[adjNode] + ways[node])%MOD;
               }
           }
       }
       return ways[n-1];
    }
};