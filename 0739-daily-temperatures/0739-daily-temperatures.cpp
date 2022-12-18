class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        stack<int> stk;
        vector<int> res(n,0);
        int i=n-1;
        while(i>=0){
            if(stk.empty() || temp[stk.top()]>temp[i]){
                if(!stk.empty()) res[i]=stk.top()-i;
                stk.push(i);
                i--;
            }
            else{
                stk.pop();
            }
        }
        return res;
    }
};