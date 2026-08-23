class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        int max_freq = 0;
        
        // 1. 統計頻率，並找出「最大頻率 (M)」
        for(char c : tasks) {
            freq[c - 'A']++;
            max_freq = max(max_freq, freq[c - 'A']);
        }
        
        // 2. 算算看有幾個任務跟最大頻率一樣多 (M_count)
        int max_count = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] == max_freq) {
                max_count++;
            }
        }
        
        // 3. 套用數學公式
        int formula_time = (max_freq - 1) * (n + 1) + max_count;
        int total_tasks = tasks.size();
        
        // 4. 回傳兩者中的最大值
        return max(formula_time, total_tasks);
    }
};