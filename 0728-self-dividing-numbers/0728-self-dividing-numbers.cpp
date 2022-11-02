class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        while(left<=right){
            int t=left;
            while(t>0){
                int div=t%10;
                if(div==0 || left%div!=0) break;
                t/=10;
            }
            if(t==0) res.push_back(left);
            left++;
        }
        return res;
    }
};