class MyStack {
public:
    vector<int> st;
    int idx;
    MyStack() {
        st.reserve(101);
        idx = 0;
    }
    
    void push(int x) {
        st[idx++] = x;
    }
    
    int pop() {
        idx--;
        return st[idx];
    }
    
    int top() {
        return st[idx - 1];
    }
    
    bool empty() {
        return idx == 0;
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