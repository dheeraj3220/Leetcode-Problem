//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
         vector<pair<int,int>> adj[n];
        for(auto road : roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> time(n,1e9);
        vector<int> ways(n,0);
        ways[0]=1;
        pq.push({0,0});
        time[0]=0;
        int count=0;
        while(!pq.empty()){
            auto it=pq.top();
            int curTime=it.first;
            int curCity=it.second;
            if(curCity==n-1) return ways[n-1];
            pq.pop();
            for(auto iter : adj[curCity]){
                int adjCity=iter.first;
                int adjCityTime=iter.second;       
                if(curTime+adjCityTime==time[adjCity]) 
                    ways[adjCity]=(ways[adjCity]%1000000007+ways[curCity]%1000000007)%1000000007;
                if(curTime+adjCityTime<time[adjCity]){
                    time[adjCity]=curTime+adjCityTime;
                    ways[adjCity]=ways[curCity];
                    pq.push({time[adjCity],adjCity});
                }      
            }
        }
        return ways[n-1]%1000000007;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends