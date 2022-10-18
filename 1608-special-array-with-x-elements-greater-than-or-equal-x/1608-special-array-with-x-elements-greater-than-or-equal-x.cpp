class Solution {
public:
    int specialArray(vector<int>& nums) {
       int arr[1001]={0};
        for(auto num :nums) arr[num]++;
        int x=nums.size();
        for(int i=0;i<=nums.size();i++){
            if(i==x) return x;
            x-=arr[i];
        }
        return -1;
    }
};