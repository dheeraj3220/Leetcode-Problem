class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int ele,count;
        for( auto num : nums){
            if(count==0) ele=num;
            if(num==ele) count++;
            else count--;
        }
        return ele;
    }
};