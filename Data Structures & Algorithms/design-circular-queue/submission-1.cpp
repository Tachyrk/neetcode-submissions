class MyCircularQueue {
public:
    vector<int> q;
    int head;
    int tail;
    int n;
    MyCircularQueue(int k) { 
        // 想一想為甚麼是 k + 1
        q = vector<int>(k + 1);
        n = k + 1;
        head = 0;
        tail = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        q[head++] = value;
        if(head >= n) head -= n;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        tail++;
        if(tail >= n) tail -= n;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[tail];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[(head - 1 + n) % n];
    }
    
    bool isEmpty() {
        return (head == tail);
    }
    
    bool isFull() {
        return (((head + 1) % n) == tail);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */