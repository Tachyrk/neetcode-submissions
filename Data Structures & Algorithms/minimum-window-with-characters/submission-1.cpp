class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (n < m) return "";

        int freq[128] = {0}; // 直接使用 ASCII 大小，程式碼更直覺
        int count = 0;
        
        for (char c : t) {
            if (freq[c] == 0) count++;
            freq[c]--;
        }

        int min_start = 0;
        int min_len = 1e9 + 7; // 用來記錄最短長度

        for (int i = 0, left = 0; i < n; i++) {
            if (freq[s[i]] == -1) {
                count--;
            }
            freq[s[i]]++;
            
            while (count == 0) {
                // 更新最短的合法窗口紀錄
                if (i - left + 1 < min_len) {
                    min_start = left;
                    min_len = i - left + 1;
                }
                
                // 準備縮小窗口，移除左邊界元素
                if (freq[s[left]] == 0) {
                    count++;
                }
                freq[s[left]]--;
                left++;
            }
        }

        return min_len > n ? "" : s.substr(min_start, min_len);
    }
};