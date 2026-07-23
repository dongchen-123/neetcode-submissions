class MinStack {
private:
    std::stack<int> m;
    std::stack<int> s_min;
public:
    MinStack() {
    }
    
    void push(int val) {
        if (this->m.empty()) this->s_min.push(val);
        else this->s_min.push(min(s_min.top(), val));
        this->m.push(val);
    }
    
    void pop() {
        this->m.pop();
        this->s_min.pop();
    }
    
    int top() {
        return this->m.top();
    }
    
    int getMin() {
        return this->s_min.top();
    }
};
