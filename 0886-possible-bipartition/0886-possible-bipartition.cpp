class Solution {
    vector<int>g[2002];
    int color[2002];
    bool bicolor;
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(auto v: dislikes)
        {
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        memset(color, 0, sizeof(color));
        for(int i=1; i<=n; i++)
        {
            if(!color[i]){
                bicolor=true;
                dfs(i, 1);
                if(!bicolor) return false;
            }
        }
        return true;
    }

    void dfs(int u, int Color)
    {
        color[u]=Color;
        for(auto v: g[u]){
            if(!color[v]){
               if(color[u]==1) dfs(v, 2);
               else dfs(v,1);
            }else if(color[v]==color[u]) {bicolor=false; return ; }

        }
    }
};