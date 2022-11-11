class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row=heights.size();
        int col=heights[0].size();
        set<pair<int,pair<int,int>>> st;
        st.insert({0,{0,0}});
        vector<vector<int>> distance(row,vector<int>(col,1e9));
        distance[0][0]=0;
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        while(!st.empty()){
            auto it=*(st.begin());
            int dist=it.first;
            int x=it.second.first;
            int y=it.second.second;
            if(x==row-1 && y==col-1) return dist;
            st.erase(it);
            for(int i=0;i<4;i++){
                int newR=x+dr[i];
                int newC=y+dc[i];
                if(newR>=0 && newR<row && newC>=0 && newC<col){
                    int curEff=max(dist,abs(heights[x][y]-heights[newR][newC]));
                    if(curEff<distance[newR][newC]){
                        if(st.count({distance[newR][newC],{newR,newC}})) 
                            st.erase({distance[newR][newC],{newR,newC}});
                        distance[newR][newC]=curEff;
                        st.insert({curEff,{newR,newC}});
                    }
                }
            }
        }
        return distance[row-1][col-1];
    }
};