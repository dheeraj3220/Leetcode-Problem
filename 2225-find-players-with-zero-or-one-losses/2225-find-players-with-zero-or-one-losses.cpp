class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> loss;
        unordered_set<int> total;
        for(auto match : matches){
            loss[match[1]]++;
            total.insert(match[0]);
            total.insert(match[1]);
        }
        vector<int> zeroLoss,oneLoss;
        
        for(auto iter=total.begin();iter!=total.end();iter++){
            int it=*iter;
            if(loss.count(it)==0) zeroLoss.push_back(it);
            else{
                if(loss[it]==1) oneLoss.push_back(it);
            }
        }
        vector<vector<int>> res;
        sort(zeroLoss.begin(),zeroLoss.end());
        sort(oneLoss.begin(),oneLoss.end());
        res.push_back(zeroLoss);
        res.push_back(oneLoss);
        return res;
    }
};