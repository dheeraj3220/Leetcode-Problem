class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      unordered_map<int,int> mapp;
        int i=0;
        for(auto num : nums ){
            if(mapp.count(num)>0 && abs(mapp[num]-i)<=k) return true;
            else mapp[num]=i;
            i++;
        }
        return false;
    }
};