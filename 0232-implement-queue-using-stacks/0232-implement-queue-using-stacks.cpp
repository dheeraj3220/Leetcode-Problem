class MyQueue {
public:
    queue<int> que; 
    MyQueue() {
       
    }
    
    void push(int x) {
        que.push(x);
        
    }
    
    int pop() {
        int top=que.front();
        que.pop();
        return top;
    }
    
    int peek() {
        return que.front();
    }
    
    bool empty() {
        return que.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */