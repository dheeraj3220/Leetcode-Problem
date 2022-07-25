class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> my_map;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(my_map.count(target-nums[i])>0)
            {
                res.push_back(my_map[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            my_map[nums[i]]=i;
        }
        
        return res;
        
        
    }
};