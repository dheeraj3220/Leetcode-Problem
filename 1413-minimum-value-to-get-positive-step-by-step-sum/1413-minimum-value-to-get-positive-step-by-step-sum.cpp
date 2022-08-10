class Solution {
public:
   int minStartValue(vector<int>& nums) {
    auto sum = 0, min_sum = 0;
    for (auto n : nums) {
        sum += n;
        min_sum = min(min_sum, sum);
    }
    return 1 - min_sum;
}
};