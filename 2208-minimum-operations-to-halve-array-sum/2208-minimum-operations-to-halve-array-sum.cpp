class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        long long sum = 0;
        for (int x : nums) {
            sum += x;
            pq.push(x);
        }
        
        double half = (double)sum / 2.0;
        int answer = 0;
        
        while (half > 0) {
            double max = pq.top();
            pq.pop();
            
            max /= 2.0;
            half -= max;
            
            if (max > 0) {
                pq.push(max);
            }
            
            answer++;
        }
        
        return answer;
    }
};






// class Solution {
// public:
//     int halveArray(vector<int>& nums) {
//         priority_queue<double> pq;
//         int countSteps=0;
//         long long initialSum=0;
//         for(auto num:nums){
//             initialSum+=num;
//             pq.push(num);
            
//         }
//         double m=(double)initialSum/2.0;
//         while(m>0){
//             int top=pq.top();
//             pq.pop();
//             top/=2.0;
//             m-=top;
//             if(top>0) pq.push(top);
            
//             countSteps++;
//         }
//         return countSteps;
//     }
// };

// // priority_queue<double> pq;
// //         long long sum = 0;
// //         for (int x : nums) {
// //             sum += x;
// //             pq.push(x);
// //         }
        
// //         double half = (double)sum / 2.0;
// //         int answer = 0;
        
// //         while (half > 0) {
// //             double max = pq.top();
// //             pq.pop();
            
// //             max /= 2.0;
// //             half -= max;
            
// //             if (max > 0) {
// //                 pq.push(max);
// //             }
            
// //             answer++;
// //         }