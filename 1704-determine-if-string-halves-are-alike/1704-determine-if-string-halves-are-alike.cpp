class Solution {
public:
    int countVowels(string str){
        int count=0;
        for(auto s : str) {
            if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u' || s=='A' || s=='E' || s=='I' || s=='O' || s=='U') count++;
        }
        return count;
    }
    bool halvesAreAlike(string s) {
        int n=s.size();
        return countVowels(s.substr(0,n/2))== countVowels(s.substr(n/2,n+1));
    }
};