class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mapp;
        for(int i=0;i<nums.size();i++){
            if(mapp.count(nums[i])==1 && abs(i-mapp[nums[i]])<=k) return true;
            else
                mapp[nums[i]]=i;
        }
        return false;
    }
};