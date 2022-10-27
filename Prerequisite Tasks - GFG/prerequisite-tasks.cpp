//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int numCourses, vector<pair<int, int> >& prerequisites) {
	    // Code here
	     vector<int> adj[numCourses];
        for(auto course : prerequisites){
            adj[course.second].push_back(course.first);
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
        return (res.size()==numCourses);
        
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends