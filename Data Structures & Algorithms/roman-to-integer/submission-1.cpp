class Solution {
public:
    int romanToInt(string s) {
        auto get_val = [](char c) {
            switch(c) {
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
                default: return 0;
            }
        };

        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int cur = get_val(s[i]);
            // 如果右邊鄰居比我大，我就要被減去
            if (i + 1 < n && cur < get_val(s[i + 1])) {
                ans -= cur;
            } else {
                ans += cur;
            }
        }
        return ans;
    }
};