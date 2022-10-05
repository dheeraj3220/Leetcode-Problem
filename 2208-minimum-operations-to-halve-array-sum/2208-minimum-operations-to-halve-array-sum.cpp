class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double countSteps=0;
        double initialSum=0;
        double curSum=0;
        for(auto num:nums){
            pq.push(num);
            initialSum+=num;
        }
        curSum=initialSum;
        while(initialSum-curSum<(initialSum/2)){
            double top=pq.top();
            pq.pop();
            pq.push(top/2);
            curSum-=top;
            curSum+=top/2;
            countSteps++;
        }
        return countSteps;
    }
};