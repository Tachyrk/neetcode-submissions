class StockSpanner {
public:
    vector<pair<int, int>> st;  
    StockSpanner() {
        st.reserve(100000);       
    }
    
    int next(int price) {
        int count = 1;
        while(!st.empty() && st.back().first <= price){
            count += st.back().second;
            st.pop_back();
        }
        st.push_back({price, count});       
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */