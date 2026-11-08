class FreqStack {
public:
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> mp;    
    stack<int> st;
    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val]++;
        st.push(val);       
        pq.push({mp[val], val});
    }
    
    int pop() {
        while(!pq.empty() && mp[pq.top().second] != pq.top().first) pq.pop();
        int max_freq = pq.top().first;
        int res;
        stack<int> temp;        
        while(mp[st.top()] != max_freq){
            temp.push(st.top());
            st.pop();
        }
        res = st.top();
        st.pop();
        mp[res]--;
        if(mp[res]) pq.push({mp[res], res});
        while(!pq.empty() && mp[pq.top().second] != pq.top().first) pq.pop();
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */