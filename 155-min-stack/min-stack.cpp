class MinStack {
public:
    stack<int> s;
    stack<int> minSt;
    MinStack() { 
        // assumption: Methods pop, top and getMin operations will always be called on non-empty stacks.       
    }
    
    void push(int value) {
        s.push(value);
        if(minSt.empty() || minSt.top() >= value) minSt.push(value);
    }
    
    void pop() {
        int top = s.top();
        if(top == minSt.top()) minSt.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */