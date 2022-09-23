class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> pref(nums.size(),0);
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target) return 1;
            if(i==0) pref[i]=nums[i];
            else pref[i]=pref[i-1]+nums[i];
            if(pref[i]>=target) mini=min(mini,i+1);
        }
        int i=0,j=0;
        while(i<nums.size() && j<nums.size()){
            if(pref[j]-pref[i]>=target) {
                mini=min(mini,j-i);
                i++;
            }
            else if((pref[j]-pref[i])<target) j++;
        }
        return mini==INT_MAX?0:mini;
        
    }
};