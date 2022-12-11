class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<long,long> mapp;
        for(auto num : nums) {
            mapp[num]++;
        }
        int maxCount=0;
        for(int i=2;i<320;i++){
            int count=0;
            for(int j=i;j<=500000;){
                if(j>319) {
                    if(mapp.count(j)==1) count++;
                    break;
                }
                if(mapp.count(j)==1){
                    count++;
                    j=j*j;
                }
                else break;
            }
            maxCount=max(count,maxCount);
        }
        if(maxCount==1 || maxCount==0) return -1;
        return maxCount;
    }
};