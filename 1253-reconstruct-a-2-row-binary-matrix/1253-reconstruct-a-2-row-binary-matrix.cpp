class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> res;
        vector<int> temp;
        res.push_back(temp);
        res.push_back(temp);
        for(int i=0;i<colsum.size();i++){
            if(colsum[i]==0) {
                res[0].push_back(0);
                res[1].push_back(0);
            }
            else if(colsum[i]==2){
               res[0].push_back(1);
               res[1].push_back(1); 
                upper--;
                lower--;
            }
            else{
                if(upper>lower){
                    res[0].push_back(1);
                    res[1].push_back(0);
                    upper--;
                }
                else{
                    res[0].push_back(0);
                    res[1].push_back(1);
                    lower--;
                }
            }
        }
        return lower||upper?vector<vector<int>>():res;
    }
};