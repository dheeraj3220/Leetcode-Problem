class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1;
        int leftmax=0,rightmax=0;
        int water=0;
        while(i<j){
            if(height[i]<=height[j]){
                leftmax=max(height[i],leftmax);
                water+=leftmax-height[i];
                i++;
            }
            else{
                rightmax=max(height[j],rightmax);
                water+=rightmax-height[j];
                j--;
            }
        }
        return water;
        
    }
};