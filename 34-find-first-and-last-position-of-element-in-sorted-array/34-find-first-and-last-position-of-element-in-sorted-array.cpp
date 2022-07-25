class Solution {
public:
    int findPositionLower(vector<int> nums,int target){
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target)
                if(mid!=0 && nums[mid-1]==target) high=mid-1;
                else
                    return mid;
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int lowerBound=findPositionLower(nums,target);
        int upperBound=findPositionLower(nums,target+1);
        if(lowerBound<nums.size() && nums[lowerBound]==target){
        res.push_back(lowerBound);
        res.push_back(upperBound-1);
        return res;
        }
        else
            return {-1,-1};
        
    }
};