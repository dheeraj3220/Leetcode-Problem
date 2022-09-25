class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++) maxi=max(maxi,nums[i]);
        int countlen=0,maxlen=0; 
        for(int i=0;i<n;i++){
            if(maxi==nums[i]){
                countlen++;
                maxlen=max(maxlen,countlen);
            }
            else countlen=0;
        }
        return maxlen;
    }
};