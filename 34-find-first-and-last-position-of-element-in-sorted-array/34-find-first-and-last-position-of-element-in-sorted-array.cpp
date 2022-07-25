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
        return -1;
    }
    int findPositionUpper(vector<int> &nums,int &target){
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target)
                if(mid!=nums.size()-1 && nums[mid+1]==target) low=mid+1;
                else
                    return mid;
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        // if(nums.size()==0) {
        //      res.push_back(-1);
        //     res.push_back(-1);
        //     return res;
        // }
        int lowerBound=findPositionLower(nums,target);
        int upperBound=findPositionUpper(nums,target);
        res.push_back(lowerBound);
        res.push_back(upperBound);
        return res;
        
    }
};