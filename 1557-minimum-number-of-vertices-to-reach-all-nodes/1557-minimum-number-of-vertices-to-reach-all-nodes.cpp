class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inOrder(n,0);
        for(auto edge : edges){
            inOrder[edge[1]]=1;
        }
        vector<int > res;
        for(int i=0;i<n;i++) {
            if(inOrder[i]==0) res.push_back(i);
        }
        return res;
    }
};