class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
        if(n<k){
            reverse(s.begin(),s.end());
            return s;
        }
        int cur=0;
        while(cur<n){
            if(cur+k<n) reverse(s.begin()+cur,s.begin()+cur+k);
            else reverse(s.begin()+cur,s.end());
            cur+=(2*k);
        }
        return s;
    }
};