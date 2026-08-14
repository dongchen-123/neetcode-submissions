class MinStack {
private:
std::stack<int> curStack;
std::stack<int> minStack;
public:
    MinStack() {
        curStack = {};
        minStack = {};
        
    }
    
    void push(int val) {
        curStack.push(val);
        if (minStack.empty()) minStack.push(val);
        else if (val <= minStack.top()) minStack.push(val);       
    }
    
    void pop() {
        if (!curStack.empty() && curStack.top() == minStack.top()) minStack.pop();
        if (!curStack.empty()) curStack.pop();
    }
    
    int top() {
        return curStack.top();
        
    }
    
    int getMin() {
        return minStack.top();
    }
};
