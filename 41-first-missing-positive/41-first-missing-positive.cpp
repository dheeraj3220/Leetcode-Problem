class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       unordered_map<int,int> mapp;
        for(int i=0;i<nums.size();i++) mapp[nums[i]]++;
        int max=0;
        for(int i=1;i<=nums.size();i++){
            if(max<i) max=i;
            if(mapp.count(i)==0) return i;
        }
        return max+1;
    }
};