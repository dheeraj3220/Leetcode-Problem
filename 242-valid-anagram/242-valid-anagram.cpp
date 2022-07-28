class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> mapp;
        for(auto iter: s)
            mapp[iter]++;
        for(auto iter: t){
            if(mapp[iter]==0) return false;
            else{
                mapp[iter]--;
            }
        }
        return true;
    }
};