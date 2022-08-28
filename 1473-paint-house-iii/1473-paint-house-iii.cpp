class Solution {
public:
    int dp[110][110][110];
    int helper(vector<int>& houses, vector<vector<int>>& cost,int target,int houseIndex,int prevColor){
        if(target<0) return 1e9;
        if(houseIndex==houses.size()){
        if(target==0) return 0;
        else return 1e9;
        }
        if(dp[houseIndex][prevColor+1][target]!=-1) return dp[houseIndex][prevColor+1][target];
        int colorCost=1e9;
        if(houses[houseIndex]==0){
            for(int i=0;i<cost[0].size();i++){
                if(prevColor==i) colorCost=min(colorCost,cost[houseIndex][i]+helper(houses,cost,target,houseIndex+1,i));
                else colorCost=min(colorCost,cost[houseIndex][i]+helper(houses,cost,target-1,houseIndex+1,i));
            }
        }
        else{
            if(prevColor==houses[houseIndex]-1) colorCost=min(colorCost,helper(houses,cost,target,houseIndex+1,prevColor));
                else colorCost=min(colorCost,helper(houses,cost,target-1,houseIndex+1,houses[houseIndex]-1));
        }
        return dp[houseIndex][prevColor+1][target]=colorCost;
        
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
       memset(dp,-1,sizeof(dp));
        int ans=helper(houses,cost,target,0,-1);
        if(ans>=1e9) return -1;
        else return ans;
    }
};