class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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