class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(j<spaces.size() && spaces[j]==i){
                res+=" ";
                j++;
            }
            res.push_back(s[i]);
        }
        return res;
    }
};