class MyStack {
public:
    int last;
    queue<int> q;
    queue<int> q2;

    MyStack() {}
    
    void push(int x) {
        q.push(x);
        last = x;
    }
    
    int pop() {
        // 搬移前 size - 1 個元素到 q2
        while (q.size() > 1) {
            last = q.front(); // 每一輪順手更新，最後停在倒數第二個元素上
            q2.push(last);
            q.pop();
        }
        
        // 此時 q 剩下最後一個元素
        int res = q.front();
        q.pop(); // q 徹底自然清空
        
        swap(q, q2); // 指針交換：q 拿回資料，q2 變回全空
        return res;
    }
    
    int top() {
        return last;
    }
    
    bool empty() {
        return q.empty();
    }
};