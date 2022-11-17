class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>  adjMat(n,vector<int>(n,1e9));
            for(auto edge : edges){
                adjMat[edge[0]][edge[1]]=edge[2];
                adjMat[edge[1]][edge[0]]=edge[2];
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j) adjMat[i][j]=0;
                }
            }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adjMat[i][j]=min(adjMat[i][j],adjMat[i][via]+adjMat[via][j]);       
                }
            }
        }
        pair<int,int> res({INT_MIN,INT_MAX}); // {edge,no. of cities}
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(adjMat[i][j]<=distanceThreshold) count++;
            }
            if(count<=res.second){
                res.first=max(res.first,i);
                res.second=count;
            }
        }
        return res.first;
        
    }
};