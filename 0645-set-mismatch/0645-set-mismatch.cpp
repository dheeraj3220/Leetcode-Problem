class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n+1,0);
        for(auto num : nums){
            res[num]++;
        }
        int missing,duplicate;
        for(int i=1;i<=n;i++){
            if(res[i]==2) duplicate=i;
            if(res[i]==0) missing=i;
        }
        return {duplicate,missing};
    }
};