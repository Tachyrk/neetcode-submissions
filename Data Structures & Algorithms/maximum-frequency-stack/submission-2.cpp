class FreqStack {
private:
    unordered_map<int, int> freq;               // val -> 出現次數
    unordered_map<int, vector<int>> group;      // frequency -> 該頻率對應的 LIFO 容器
    int max_freq;

public:
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int val) {
        int f = ++freq[val];
        if (f > max_freq) {
            max_freq = f;
        }
        // 將 val 加入對應頻率的層級中
        group[f].push_back(val);
    }
    
    int pop() {
        // 1. 直接取出當前最高頻率層級中最晚加入的元素
        int val = group[max_freq].back();
        group[max_freq].pop_back();

        // 2. 更新該元素的頻率
        freq[val]--;

        // 3. 若當前最高頻率層已經沒有元素，最高頻率降一層
        if (group[max_freq].empty()) {
            max_freq--;
        }

        return val;
    }
};