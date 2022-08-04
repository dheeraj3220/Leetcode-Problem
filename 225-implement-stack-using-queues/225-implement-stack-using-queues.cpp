#include<queue>
class MyStack {
public:
    queue <int>q1;
    queue <int>q2;
    MyStack() {
    }
    
    void push(int x) {
        if(q1.size()==0)q1.push(x);
        else{
            q2.push(x);
            while(!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }
    
    int pop() {
        int ans=-1;
        if(!q1.empty()){ 
            ans=q1.front();
            q1.pop();
        }
        else if(!q2.empty()){
            ans=q2.front();
            q2.pop();  
        } 
        return ans;
    }
    
    int top() {
        int ans=-1;
        if(!q1.empty()) ans=q1.front();
        else if(!q2.empty()) ans=q2.front();
        return ans;
    }
    
    bool empty() {
        return q1.size()==0 && q2.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */