class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int i=n-1;
        while(i>=0 && !(s[i]>='A' && s[i]<='Z') && !(s[i]>='a' && s[i]<='z')) i--;
        int count=0;
        while(i>=0 && s[i]!=' ') {
            count++;
            i--;
        }
        return count;
    }
};