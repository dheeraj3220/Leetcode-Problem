class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int sum=0;
        for(auto num : nums) sum=sum^num;
        return sum;
    }
};