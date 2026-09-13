class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minpq;
    priority_queue<int> maxpq;
    int count;
    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        count++;
        // 1. 先進 maxpq，過濾出較小那一半中的最大值
        maxpq.push(num);
        // 2. 把最大值送進 minpq，保證 minpq 裡面的所有數都 >= maxpq 裡面的數
        minpq.push(maxpq.top());
        maxpq.pop();
        if(minpq.size() > maxpq.size() + 1){
            int node = minpq.top();
            minpq.pop();
            maxpq.push(node);
        }
    }
    
    double findMedian() {
        if(count & 1) return minpq.top();
        double num1 = minpq.top();
        double num2 = maxpq.top();
        return (num1 + num2) / 2;
    }
};
