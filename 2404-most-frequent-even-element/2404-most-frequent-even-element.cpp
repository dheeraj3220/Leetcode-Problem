class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int arr[100001]={0};
        for(auto iter:nums){
            if(iter%2==0) arr[iter]++;
        }
        int res=-1;
        int maxi=0;
        for(int i=0;i<100001;i++){
            if(maxi<arr[i]) {
                res=i;
                maxi=arr[i];
            }
        }
        return res;
    }
};