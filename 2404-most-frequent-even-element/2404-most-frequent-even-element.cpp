class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> mapp;
        for(auto iter:nums){
            if(iter%2==0) mapp[iter]++;
        }
        int res=-1;
        int maxi=0;
        for(auto i=mapp.begin();i!=mapp.end();i++){
            if(i->second>maxi){
                res=i->first;
                maxi=i->second;
            }
        }
        return res;
    }
};