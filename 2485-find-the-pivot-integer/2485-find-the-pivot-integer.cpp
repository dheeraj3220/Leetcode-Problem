class Solution {
public:
    int pivotInteger(int n) {
       int sum=n*(n+1)/2;
        int prev=0;
        int ele=1;
        while(sum>prev){
            if(prev+ele==sum) return ele;
            prev+=ele;
            sum-=ele;
            ele++;
        }
        return -1;
    }
};