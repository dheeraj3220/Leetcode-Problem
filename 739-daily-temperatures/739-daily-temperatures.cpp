class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> res(temperatures.size(),0);
        for(int i=temperatures.size()-1;i>=0;i--){
            if(stk.empty()) stk.push(i);
            else{
                while(!stk.empty() && temperatures[stk.top()]<=temperatures[i]) stk.pop();
                if(!stk.empty() && temperatures[stk.top()]>temperatures[i]) {
                    res[i]=stk.top()-i;
                }
                stk.push(i);
            }
        }
        return res;
    }
};