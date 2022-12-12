class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(digits.back()!=9) digits[n-1]+=1;
        else{
            int i=n-1;
            while(i>=0 && digits[i]==9){
                digits[i]=0;
                i--;
            }
            if(i==-1){
                vector<int> res(n+1,0);
                res[0]=1;
                return res;
            }
            else digits[i]+=1;
        }
        return digits;
    }
};