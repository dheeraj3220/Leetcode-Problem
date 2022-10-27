//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int numCourses, int m, vector<vector<int>> prerequisites) 
    {
        //code here
         vector<int> adj[numCourses];
        for(auto course : prerequisites){
            adj[course[1]].push_back(course[0]);
        }
        vector<int> inDegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto course : adj[i]){
                inDegree[course]++;
            }
        }
        queue<int> que;
        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i]==0) que.push(i);
        }
        vector<int> res;
        while(!que.empty()){
            int course=que.front();
            que.pop();
            res.push_back(course);
            for(auto it : adj[course]){
                inDegree[it]--;
                if(inDegree[it]==0) que.push(it);
            }
        }
        if(res.size()!=numCourses) return {};
        return res;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends