class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,maxWater=0,curArea=0;
        while(i<j){
            curArea=min(height[i],height[j])*(j-i);
            height[i]>height[j]?j--:i++;
            maxWater=max(curArea,maxWater);
        }
        return maxWater;
    }
};