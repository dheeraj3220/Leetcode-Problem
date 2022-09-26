class Solution {
public:
    int arrangeCoins(int n) {
        int count=0,i=1;
        while(i<=n){
            n=n-i;
            i++;
            count++;
        }
        return count;
    }
};