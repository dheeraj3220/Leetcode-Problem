class Solution {
public:
	void dfs(int x, int y, int num, vector<vector<int>>& v, vector<vector<int>>& heights){
		if(x<0 || x>=heights.size() || y<0 || y>=heights[0].size() || heights[x][y]<num || v[x][y]){return;}
		v[x][y]=1;
		dfs(x-1, y, heights[x][y], v, heights);
		dfs(x, y-1, heights[x][y], v, heights);
		dfs(x+1, y, heights[x][y], v, heights);
		dfs(x, y+1, heights[x][y], v, heights);
	}
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		vector<vector<int>>v1(heights.size(), vector<int>(heights[0].size(), 0));
		vector<vector<int>>v2(heights.size(), vector<int>(heights[0].size(), 0));
		for(int i=0; i<heights.size(); i++){
			if(!v1[i][0]){dfs(i, 0, heights[i][0], v1, heights);}
			if(!v2[i][heights[0].size()-1]){dfs(i, heights[0].size()-1, heights[i][heights[0].size()-1], v2, heights);}
		}
		for(int i=0; i<heights[0].size(); i++){
			if(!v1[0][i]){dfs(0, i, heights[0][i], v1, heights);}
			if(!v2[heights.size()-1][i]){dfs(heights.size()-1, i, heights[heights.size()-1][i], v2, heights);}
		}
		// for(int i=0; i<heights.size(); i++){
		//     for(int j=0; j<heights[0].size(); j++){
		//         cout<<v1[i][j]<<" ";
		//     }cout<<endl;
		// }cout<<endl;
		// for(int i=0; i<heights.size(); i++){
		//     for(int j=0; j<heights[0].size(); j++){
		//         cout<<v2[i][j]<<" ";
		//     }cout<<endl;
		// }
		vector<vector<int>>ans;
		for(int i=0; i<heights.size(); i++){
			for(int j=0; j<heights[0].size(); j++){
				if(v1[i][j] && v2[i][j]){
					ans.push_back({i, j});
				}
			}
		}
		return ans;
	}
};



// class Solution {
// public:
//     bool dfs(vector<vector<int>>&heights,int i,int j,vector<vector<int>> &flow,int ocean){
//         if(flow[i][j]==1) return true;
//         if(ocean==0){
//             if(i==heights.size()-1 || j==heights[0].size()-1){
//                 flow[i][j]=1;
//                 return true;  
//             } 
//         }
//         else{
//             if(i==0 || j==0){
//                 flow[i][j]=1;
//                 return true;
//             }
//         }
//         int dr[]={-1,0,1,0};
//         int dc[]={0,-1,0,1};
//         int finalAns=false;
//         flow[i][j]=-1;
//         for(int k=0;k<4;k++){
//             int x=i+dr[k];
//             int y=j+dc[k];
//             if(x>=0 && y>=0 && x<heights.size() && y<heights[0].size() && heights[i][j]>=heights[x][y] && flow[x][y]!=-1){
//                 bool ans=dfs(heights,x,y,flow,ocean);
//                 if(ans==true) finalAns=ans;
//             }
//         }
//         if(finalAns) flow[i][j]=1;
//         else flow[i][j]=0;
//         return flow[i][j]==1 ;
        
//     }
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         int n=heights.size(),m=heights[0].size();
//         vector<vector<int>> toPacific(n,vector<int>(m,0));
//         vector<vector<int>> toAtlantic(n,vector<int>(m,0));
//         // int ocean=0; // 0->pacific 1->atlantic
        
//         for(int j=0;j<m;j++) {
//            if(toAtlantic[0][j]!=1) bool s=dfs(heights,0,j,toAtlantic,0);
//         }
//         for(int i=0;i<n;i++){
//             if(toAtlantic[i][0]!=1)  bool s=dfs(heights,i,0,toAtlantic,0);
//         }
//         for(int j=m-1;j>=0;j--) {
//            if(toPacific[n-1][j]!=1)  bool s=dfs(heights,n-1,j,toPacific,1);
//         }
//         for(int i=n-1;i>=0;i--){
//            if(toPacific[i][m-1]!=1)  bool s= dfs(heights,i,m-1,toPacific,1);
//         }
//         vector<vector<int>> res;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(toAtlantic[i][j]==toPacific[i][j] && toPacific[i][j]==1 )
//                 {
//                     vector<int> temp;
//                     temp.push_back(i);
//                     temp.push_back(j);
//                     res.push_back(temp);
//                 }
//             }
//         }
        
//         return res;
//     }
// };