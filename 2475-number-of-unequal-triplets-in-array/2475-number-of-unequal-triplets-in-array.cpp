class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]!=nums[j] && nums[i]!=nums[k] && nums[k]!=nums[j]) count++;
                }
            }
        }
        return count;
    }
};