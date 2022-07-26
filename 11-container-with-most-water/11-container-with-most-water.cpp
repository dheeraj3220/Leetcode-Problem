class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int maxres=0,curarea=0;
        while(i<j){
          int temp=min(height[i],height[j]);
            curarea=temp*(j-i);
            height[i]>height[j]?j--:i++;
            maxres=max(curarea,maxres);
        }
        return maxres;
    }
};