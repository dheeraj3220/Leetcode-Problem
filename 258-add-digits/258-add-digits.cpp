class Solution {
public:
    int addDigits(int num) {
       if(num<=9) return num;
       int newDigit=0;
        while(num>0){
            newDigit+=num%10;
            num/=10;
        }
        return addDigits(newDigit);
        
    }
};