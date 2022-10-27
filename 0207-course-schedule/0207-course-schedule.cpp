class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> inDegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto course : adj[i]){
                inDegree[course]++;
            }
        }
        queue<int> que; 
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0) que.push(i);
        }
        int count=0;
        while(!que.empty()){
            int course=que.front();
            que.pop();
            count++;
            for(auto cur : adj[course]){
                inDegree[cur]--;
                if(inDegree[cur]==0) que.push(cur);
            }
        }
        return numCourses==count;
    }
};