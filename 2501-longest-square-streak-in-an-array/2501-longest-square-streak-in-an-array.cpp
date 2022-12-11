class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<long long> mySet;
        for(auto num : nums) {
            mySet.insert(num);
        }
        int maxCount=0;
        for(auto i=mySet.begin();i!=mySet.end();i=mySet.begin()){
            int count=1;
            long long ft=*i;
            if(ft>320) break;
            while(mySet.count(ft*ft)==1){
                count++;
                mySet.erase(ft);
                ft=ft*ft;
            }
            mySet.erase(ft);
            maxCount=max(count,maxCount);
        }
        if(maxCount==1 || maxCount==0) return -1;
        return maxCount;
    }
};