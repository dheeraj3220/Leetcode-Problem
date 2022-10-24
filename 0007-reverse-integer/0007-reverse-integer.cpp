class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while (x) {
            long long temp = ans * 10 + x % 10;
            ans = temp;
            x /= 10;
        }
        if(ans<INT_MIN || ans>INT_MAX) return 0;
        return ans;
    }
};