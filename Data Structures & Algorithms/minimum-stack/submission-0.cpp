class MinStack {
public:
    int buffer[30001];
    int min_record[30001];
    int index;
    MinStack() {      
        index = 0;
    }
    
    void push(int val) {
        buffer[index] = val;
        min_record[index] = val;
        if(index > 0) min_record[index] = min(min_record[index], min_record[index - 1]);
        index++;
    }
    
    void pop() {
        index--;
    }
    
    int top() {
        return buffer[index - 1];
    }
    
    int getMin() {
        return min_record[index - 1];
    }
};
