class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<long long> mapp;
        for(auto num : nums) {
            mapp.insert(num);
        }
        long long maxCount=0;
        for(auto i=mapp.begin();i!=mapp.end();i=mapp.begin()){
            long long count=1;
            long long ft=*i;
            if(ft>320) break;
            while(mapp.count(ft*ft)==1){
                count++;
                mapp.erase(ft);
                ft=ft*ft;
            }
            mapp.erase(ft);
            maxCount=max(count,maxCount);
        }
        if(maxCount==1 || maxCount==0) return -1;
        return maxCount;
    }
};