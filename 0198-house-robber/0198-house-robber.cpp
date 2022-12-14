class Solution {
public:
    int rob(vector<int>& nums) {
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size();i++){
            int notRobbed=prev;
            int robbed=nums[i];
            if(i>1)robbed+=prev2;
            int curi=max(notRobbed,robbed);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
};