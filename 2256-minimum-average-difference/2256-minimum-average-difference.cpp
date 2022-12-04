class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long> right(n,0);
        vector<long> left(n,0);
        int i=0,j=n-1;
        right[i]=nums[i];
        left[j]=nums[j];
        i++;
        j--;
        while(i<n){
            right[i]=right[i-1]+nums[i];
            left[j]=left[j+1]+nums[j];
            i++;
            j--;
        }
        // vector<int> res;
        int ans=INT_MAX;
        int index=0;
        for(int i=0;i<n;i++){
            int absAvg;
            if(i!=n-1) absAvg=abs((right[i]/(i+1))-(left[i+1]/(n-i-1)));
            else absAvg=right[i]/n;
            // res.push_back(absAvg);
            if(ans>absAvg){
                ans=absAvg;
                index=i;
            }
        }
        return index;
    }
};