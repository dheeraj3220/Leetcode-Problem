class Solution {
public:
    int tribonacci(int n) {
        if(n==0 ||n==1) return n;
        if(n==2) return 1;
        int a=1;
        int b=1;
        int c=0;
        for(int i=3;i<=n;i++){
            int cur=a+b+c;
            c=b;
            b=a;
            a=cur;
        }
        return a;
    }
};