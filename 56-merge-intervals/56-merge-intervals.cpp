class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        vector<int> temp(2,-1);
        for(int i=0;i<intervals.size();i++){
            if(temp[1]!=-1 && temp[1]>=intervals[i][0]){
                temp[1]=max(temp[1],intervals[i][1]);
                continue;
            }
            if(temp[1]!=-1) res.push_back(temp);
            temp[0]=intervals[i][0];
            temp[1]=intervals[i][1];
        }
        res.push_back(temp);
        return res;
    }
};