class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for(auto num : nums)
          s.push_back(to_string(num));
        sort(s.begin(),s.end(),[](string &s1, string &s2){ return s1+s2>s2+s1; });
        string res;
        for(auto it : s) res+=it;
         while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return res;
    }
};