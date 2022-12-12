class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
        string res;
        while(i>=0 || j>=0 || carry>0){
            int tempSum=0;
            if(i>=0) tempSum+=(num1[i]-'0') ;
            if(j>=0) tempSum+=(num2[j]-'0') ;
            tempSum+=carry;
            int tempDigit=tempSum%10;
            carry=tempSum/10;
            res.push_back((tempDigit +'0'));
            i--;
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};