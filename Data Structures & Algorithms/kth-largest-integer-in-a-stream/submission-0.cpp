class KthLargest {
public:
    struct MyComp{
        bool operator()(const auto &a, const auto &b){
            return a > b;
        }
    };
    priority_queue<int, vector<int>, MyComp> q; //我知道可以用 greater<int>
    int limit;
    KthLargest(int k, vector<int>& nums) {
        q = priority_queue<int, vector<int>, MyComp> ();
        limit = k;
        for(int num : nums){
            q.push(num);
            if(q.size() > limit) q.pop();
        }         
    }
    
    int add(int val) {
        q.push(val);
        if(q.size() > limit) q.pop();
        return q.top();
    }
};
