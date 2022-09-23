class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        int j=nums.size()-2;
        int pre=1,suf=1;
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            left[i]=left[i-1]*nums[i];
            right[j]=right[j+1]*nums[j];
            j--;
        }
        vector<int> res(n,1);
        for(int i=0;i<n;i++){
            if(i==0) res[i]=right[i+1];
            else if(i==n-1) res[i]=left[i-1];
            else res[i]=left[i-1]*right[i+1];
        }
        return res;
    }
};