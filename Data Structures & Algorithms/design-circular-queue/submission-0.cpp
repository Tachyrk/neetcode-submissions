class MyCircularQueue {
public:
    vector<int> q;
    int head;
    int tail;
    int n;
    MyCircularQueue(int k) {
        q = vector<int>(k + 1);
        n = k + 1;
        head = 0;
        tail = 0;
    }
    
    bool enQueue(int value) {
        if(((head + 1) % n) == tail) return false;
        q[head++] = value;
        if(head >= n) head -= n;
        return true;
    }
    
    bool deQueue() {
        if(head == tail) return false;
        tail++;
        if(tail >= n) tail -= n;
        return true;
    }
    
    int Front() {
        if(head == tail) return -1;
        return q[tail];
    }
    
    int Rear() {
        if(head == tail) return -1;
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