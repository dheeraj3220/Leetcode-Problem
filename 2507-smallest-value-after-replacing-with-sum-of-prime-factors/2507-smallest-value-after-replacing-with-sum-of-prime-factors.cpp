class Solution {
public:
     bool isPrime(int n){
         if(n<=2) return true;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }
    
    int smallestValue(int n) {
        while(!isPrime(n)){
           int sum=0;
           int prev=n;
           int i=2;
           while(n>1){
               if(n%i==0) {
                   sum+=i;
                   n/=i;
               }
               else if(isPrime(n)){
                   sum+=n;
                   break;
               }
               else i++;
           }
           cout<<sum<<endl;
           n=sum;
           if(n==prev) return n;
       }
        return n;
    }
    
};