class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mySet;
        for(auto num : nums) {
            if(mySet.insert(num).second) mySet.insert(num);
            else return true;
        }
        return false;
    }
};