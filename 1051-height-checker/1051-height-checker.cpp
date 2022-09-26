class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp=heights;
        sort(temp.begin(),temp.end());
        int count=0,i=0;
        for(auto height : heights) {
            if(temp[i++]!=height) count++;
        }
        return count;
    }
};