class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> st;
    int max_freq;
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int val) {
        int f = ++freq[val];
        st[f].push_back(val);
        max_freq = max(max_freq, f);
    }
    
    int pop() {
        int res = st[max_freq].back();
        st[max_freq].pop_back();
        if(st[max_freq].empty()) max_freq--;
        freq[res]--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */