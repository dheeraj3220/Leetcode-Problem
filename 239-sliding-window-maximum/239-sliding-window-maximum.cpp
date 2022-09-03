class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;
        int j=0,i=0,maxi=INT_MIN;
        vector<int> res;
        while(j<nums.size()){
            while(!que.empty()&&que.back()<nums[j]) que.pop_back();
            que.push_back(nums[j]);
            if(j-i+1<k){
                j++;
                continue;
            }
            if(j-i+1>=k){
                res.push_back(que.front());
                if(nums[i]==que.front()) que.pop_front();
                i++;
                j++;
            }
        }
        return res;
        
    }
};