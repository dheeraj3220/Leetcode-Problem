//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        for(auto edge : edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        set<pair<int,int>> st;
        vector<pair<int,int>> distance(n+1,{-1,1e9});
        distance[1]={-1,0};
        st.insert({0,1});
        while(!st.empty()){
            auto it=*(st.begin());
            int node=it.second;
            int dist=it.first;
            st.erase(it);
            for(auto adjEdge : adj[node]){
                int adjE=adjEdge.first;
                int adjW=adjEdge.second;
                if(adjW+dist < distance[adjE].second){
                    if(st.count({distance[adjE].second,adjE})) 
                        st.erase({distance[adjE].second,adjE});
                    distance[adjE]=make_pair(node,(adjW+dist));
                    st.insert(make_pair(distance[adjE].second,adjE));
                }
            }
        }
        // for(int i=0;i<=n;i++) cout<<i<<". "<< distance[i].first << " " << distance[i].second <<endl;
        vector<int> route;
        int i=n;
        while(i>0){
            if(distance[i].first==-1 && i!=1) return {-1};
            route.push_back(i);
            // cout<<i<<" ";
            i=distance[i].first;
        }
        reverse(route.begin(),route.end());
        route[0]=1;
        return route;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends