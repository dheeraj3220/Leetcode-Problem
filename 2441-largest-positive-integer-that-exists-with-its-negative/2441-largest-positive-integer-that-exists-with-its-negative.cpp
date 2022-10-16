class Solution {
public:
    int findMaxK(vector<int>& nums) {
       int maxi=INT_MIN;
        unordered_map<int,int> mapp;
        for(auto num : nums){
            if(mapp.count(-num)==1){
                maxi=max(maxi,abs(num));
            }
            mapp[num];
        }
        return maxi==INT_MIN?-1:maxi;
    }
};