class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long t=abs(n);
        while(t){
            if(t&1){
                ans=ans*x;
            }
            x=x*x;
            t>>=1;
        }
        if(n<0) return 1/ans;
        else return ans;
        
    }
};