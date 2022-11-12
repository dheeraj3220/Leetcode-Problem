//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
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

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends