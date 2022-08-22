class Solution {
public:
    string removeDuplicates(string s) {
         string res;
        for(int i=0; i<s.size(); i++){
            if( res.empty() ) res += s[i];
            else {
                if( res[res.length()-1] == s[i] ) res.resize(res.length()-1);
                else res += s[i];
            }
        } return res;
    }
};