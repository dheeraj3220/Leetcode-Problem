class Solution {
public:
    int search(vector<int>& nums, int target,int low=-1,int high=-1) {
        if(low>high)
            return -1;
        if(low<0)
        {
            low=0;
            high=nums.size()-1;
        }
        int mid=(low+high)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]<target)
            return search(nums,target,mid+1,high);
        else
            return search(nums,target,low,mid-1);
        
    }
};