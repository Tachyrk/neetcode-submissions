class MyStack {
public:
    int sz;
    int last;
    queue<int> q;
    queue<int> q2;
    MyStack() {
        sz = 0;        
    }
    
    void push(int x) {
        q.push(x);
        sz++;
        last = x;
    }
    
    int pop() {
        int temp;
        for(int i = 0; i < sz - 1; i++){
            temp = q.front();
            q.pop();
            q2.push(temp);
        }
        last = temp;
        sz--;
        temp = q.front();
        q.pop();
        swap(q, q2);       
        return temp;
    }
    
    int top() {
        return last;
    }
    
    bool empty() {
        return q.empty();
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