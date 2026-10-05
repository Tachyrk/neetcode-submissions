class MyQueue {
private:
    stack<int> input;
    stack<int> output;
    void convert(){
        if(output.empty()){
            while(!input.empty()){
                int x = input.top();
                input.pop();
                output.push(x);
            }
        }
    }
public:    
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        convert();
        int x = output.top();
        output.pop();
        return x;
    }
    
    int peek() {
        convert();
        int x = output.top();       
        return x;
    }
    
    bool empty() {
        return input.empty() && output.empty();
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