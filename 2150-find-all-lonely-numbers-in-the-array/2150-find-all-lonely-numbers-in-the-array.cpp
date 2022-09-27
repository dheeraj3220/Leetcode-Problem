class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mapp;
        vector<int> res;
        for(auto iter : nums) mapp[iter]++;
        for(auto i=mapp.begin();i!=mapp.end();i++){
            if(i->second==1 && mapp.count(i->first+1)==0 && mapp.count(i->first-1)==0) 
                res.push_back(i->first);
        }
        return res;
    }
};