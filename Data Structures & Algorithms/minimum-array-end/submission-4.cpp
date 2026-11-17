class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        long long temp = n - 1;
        int j = 0; // 指向 ans 目前檢查到的位元位置

        for (int i = 0; i < 32; ++i) {
            // 找到 ans 中下一個為 0 的空位
            while ((ans >> j) & 1) {
                ++j;
            }
            // 如果 temp 的第 i 位是 1，就填進這個空位
            if ((temp >> i) & 1) {
                ans |= (1LL << j);
            }
            ++j; // 這個空位已經用掉（或保留為 0），指標往左移一位
        }
        return ans;
    }
};