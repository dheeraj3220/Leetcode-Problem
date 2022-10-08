class Solution {
public:
    // int threeSumClosest(vector<int>& nums, int target) {
    //     int n=nums.size();
    //     sort(nums.begin(),nums.end());
    //     int closetSum=1e9;
    //     for(int k=0;k<n;k++){
    //         int i=k+1,j=n-1;
    //         while(i<j){
    //             if(abs(target-closetSum)>abs(target-(nums[k]+nums[i]+nums[j]))) closetSum=nums[k]+nums[i]+nums[j];
    //             if(nums[i]+nums[j]+nums[k]==target) return target;
    //             else if(nums[i]+nums[j]<target) i++;
    //             else j--;
    //         }
    //     }
    //     return closetSum;
    // }
    int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size() < 3) return 0;
    int closest = nums[0]+nums[1]+nums[2];
    sort(nums.begin(), nums.end());
    for(int first = 0 ; first < nums.size()-2 ; ++first) {
        if(first > 0 && nums[first] == nums[first-1]) continue;
        int second = first+1;
        int third = nums.size()-1;            
        while(second < third) {
            int curSum = nums[first]+nums[second]+nums[third];
            if(curSum == target) return curSum;
            if(abs(target-curSum)<abs(target-closest)) {
                closest = curSum;
            }
            if(curSum > target) {
                --third;
            } else {
                ++second;
            }
        }
    }
    return closest;
}
};