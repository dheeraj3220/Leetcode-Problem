// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>  pq;
        // vector<int > distance(V,1e9);
        // distance[S]=0;
        // pq.push({0,S});
        // while(!pq.empty()){
        //     int curNode=pq.top().second;
        //     int curDist=pq.top().first;
        //     pq.pop();
        //     for(auto node : adj[curNode]){
        //         if(curDist+node[1] < distance[node[0]]){
        //             distance[node[0]]=curDist+node[1];
        //             pq.push({distance[node[0]],node[0]});
        //         }
        //     }
        // }
        // return distance;
        set<pair<int,int >> mySet;
        vector<int> distance(V,1e9);
        distance[S]=0;
        mySet.insert({0,S});
        while(!mySet.empty()){
            auto it=*(mySet.begin());
            int edgeWeight=it.first;
            int edge=it.second;
            mySet.erase(it);
            for(auto adjEdge : adj[edge] ){
                if(edgeWeight+adjEdge[1] < distance[adjEdge[0]] ){
                    if(mySet.count({distance[adjEdge[0]],adjEdge[0]})) 
                        mySet.erase({distance[adjEdge[0]],adjEdge[0]});
                    distance[adjEdge[0]]=edgeWeight+adjEdge[1];
                    mySet.insert({distance[adjEdge[0]],adjEdge[0]});
                }
            }
        }
        return distance;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends