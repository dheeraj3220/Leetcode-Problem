//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
  
     int orangesRotting(vector<vector<int>>& grid) {
        int inOranges=0;
        queue<pair<pair<int,int>,int>> que;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 || grid[i][j]==2) inOranges++;
                if(grid[i][j]==2){
                    que.push({{i,j},0});
                    visited[i][j]=2;
                    inOranges--;
                }
                
            }
        }
        
        int time =0;
        while(!que.empty()){
            int x=que.front().first.first;
            int y=que.front().first.second;
            time =que.front().second;
            que.pop();
            if(x+1<grid.size() && visited[x+1][y]!=2 && grid[x+1][y]==1){
                que.push({{x+1,y},time+1});
                visited[x+1][y]=2;
                inOranges--;
            }
            if(x-1>=0 && visited[x-1][y]!=2 && grid[x-1][y]==1){
                que.push({{x-1,y},time+1});
                visited[x-1][y]=2;
                inOranges--;
            }
            if(y+1<grid[0].size() && visited[x][y+1]!=2 && grid[x][y+1]==1){
                que.push({{x,y+1},time+1});
                visited[x][y+1]=2;
                inOranges--;
            }
            if(y-1>=0 && visited[x][y-1]!=2 && grid[x][y-1]==1){
                que.push({{x,y-1},time+1});
                visited[x][y-1]=2;
                inOranges--;
            }
        }
        if(inOranges==0) return time;
        else return -1;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends