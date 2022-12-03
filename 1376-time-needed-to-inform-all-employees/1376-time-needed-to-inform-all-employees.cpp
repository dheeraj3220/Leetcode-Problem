class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1 ) adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>> que;
        que.push({headID,0});
        int maxTime=0;
        while(!que.empty()){
            auto it=que.front();
            int node=it.first;
            int time=it.second;
            maxTime=max(maxTime,time);
            que.pop();
            for(auto subOrdinate : adj[node]){
                que.push({subOrdinate,time+informTime[node]});
            }
        }
        return maxTime;
    }
};