class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> mapp;
        for(auto num : nums) mapp[num]++;
        int i=0,j=0;
        while(j<nums.size()){
            if(mapp.count(nums[j])==1 && mapp[nums[j]]>=2){
                nums[i++]=nums[j];
                nums[i++]=nums[j];
            }
            else if(mapp.count(nums[j])==1)
            {
                nums[i++]=nums[j];
            }
            if(mapp.count(nums[j])==1) mapp.erase(nums[j]);
            j++;
        }
        return i;
    }
};