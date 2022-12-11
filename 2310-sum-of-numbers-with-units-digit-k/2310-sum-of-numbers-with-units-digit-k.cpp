class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0) return 0;
        if(num%10==k) return 1;
        int count=1;
        while(count<10){
            if(k%2==0 && (num%10)%2==1) return -1;
            num=num-k;
            count++;
            if(num%10==k) return count;
        }
        return -1;
        
    }
};