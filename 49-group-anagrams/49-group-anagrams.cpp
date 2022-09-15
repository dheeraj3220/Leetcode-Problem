class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> mapp;
        for(int i=0;i<strs.size();i++){
            string str=strs[i];
            sort(str.begin(),str.end());
            mapp[str].push_back(i);
        }
        vector<vector<string>> res;
        for(auto i=mapp.begin();i!=mapp.end();i++){
            vector<string> ans;
            for(int j=0;j<i->second.size();j++){
                ans.push_back(strs[i->second[j]]);
            }
            res.push_back(ans);
        }
        return res;
    }
};