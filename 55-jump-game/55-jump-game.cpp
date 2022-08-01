class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        int maxi=0;
        for(int i=0;i<n-1 && maxi>=i;i++){
            maxi=max(maxi,i+nums[i]);
            if(maxi>=n-1) return true;
        }
        return false;
    }
};