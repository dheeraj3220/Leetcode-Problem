class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n=vals.size();
        
        
        vector<vector<int>> v(n);
        
        for(int i=0;i<edges.size();i++)
        {
             v[edges[i][0]].push_back(vals[edges[i][1]]);
              v[edges[i][1]].push_back(vals[edges[i][0]]);
        }
        int maxSum=INT_MIN;
        for(int i=0;i<n;i++)
        {
             int curSum=vals[i];
             sort(v[i].begin(),v[i].end(),greater<int>());
            
             for(int j=0;j<min((int)v[i].size(),k);j++)
                  curSum+=max(0,v[i][j]);
            maxSum=max(maxSum,curSum);
        }
        return maxSum;
//         
    }
};