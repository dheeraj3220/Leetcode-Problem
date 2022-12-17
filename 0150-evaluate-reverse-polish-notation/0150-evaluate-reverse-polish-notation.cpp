class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> stk;
        for(auto it : tokens){
            if(it!="+" && it!="-" && it!="/" && it!="*"){
                long long temp=stoi(it);
                stk.push(temp);
                continue;
            }
            long long b=stk.top();
            stk.pop();
            long long a=stk.top();
            stk.pop();
            if(it=="+") stk.push(a+b);
            else if(it=="-") stk.push(a-b);
            else if(it=="*") stk.push(a*b);
            else stk.push(a/b);
        }
        return stk.top();
    }
};