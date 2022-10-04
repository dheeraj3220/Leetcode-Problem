class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<vector<int>> res (costs.size(),vector<int>(3,0));
        for(int i=0;i<costs.size();i++){
            res[i][0]=(costs[i][1]-costs[i][0]);
            res[i][1]=costs[i][0];
            res[i][2]=costs[i][1];
        }
        sort(res.begin(),res.end());
        int sum=0;
        for(int i=0;i<costs.size();i++){
            if(i<costs.size()/2) sum+=res[i][2];
            else sum+=res[i][1];
        }
        return sum;
        
        
        
        
        
        
        
        
        
        
        
    }
};