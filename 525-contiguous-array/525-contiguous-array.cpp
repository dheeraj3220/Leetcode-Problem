class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int ,int > mapp;
        int sum=0,maxlen=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]==1?1:-1;
            if(sum==0) maxlen=i+1;
            if(mapp.count(sum)==1){
                maxlen=max(maxlen,i-mapp[sum]);
            }
            else{
                mapp[sum]=i;
            }
        }
        return maxlen;
        
    }
};