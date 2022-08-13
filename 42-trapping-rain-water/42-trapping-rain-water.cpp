class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> pref(n,-1);
        vector<int> suff(n,-1);
        int maxi=0;
        int rmax=0;
        for(int i=0,j=n-1;i<n;i++,j--) {
            maxi=max(maxi,height[i]);
            pref[i]=maxi;
            rmax=max(rmax,height[j]);
            suff[j]=rmax;
        }
        int water=0;
        for(int i=0;i<n;i++){
            water+=min(pref[i],suff[i])-height[i];
        }
        return water;
        
    }
};