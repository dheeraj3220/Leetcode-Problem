class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int > subans;
        int n=nums.size();
        int temp=INT_MIN,low ,high,prevlow=INT_MIN,prevhigh=INT_MAX,sum=0;
        for(int i=0;i<n-2;i++)
        {
            if(temp==nums[i]) continue;
            low=i+1;
            high=n-1;
            prevlow=INT_MIN;
            prevhigh=INT_MAX;
            while(low<high)
            {
                if(nums[low]==prevlow || nums[high]==prevhigh)
                {
                    if(nums[low]==prevlow) low++;
                    else
                        high--;
                    continue;
                }
                sum=nums[i]+nums[low]+nums[high];
                if(sum==0)
                {
                    subans.push_back(nums[i]);
                    subans.push_back(nums[low]);
                    subans.push_back(nums[high]);
                    prevlow=nums[low];
                    prevhigh=nums[high];
                    ans.push_back(subans);
                    subans.clear();
                }
                else if(sum<0) low++;
                else if(sum>0) high--;       
            }
            temp=nums[i];
        }
        return ans;
    }
};