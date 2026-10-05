class Solution {
public:
    bool validPalindrome(string s) {
        // 輔助函式：檢查閉區間 [l, r] 是否為合法迴文
        auto isPalindrome = [&](int l, int r) {
            while (l < r) {
                if (s[l] != s[r]) return false;
                l++;
                r--;
            }
            return true;
        };

        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                // 遇到不匹配，分別嘗試跳過左端點或右端點
                return isPalindrome(left + 1, right) || isPalindrome(left, right - 1);
            }
            left++;
            right--;
        }

        return true;
    }
};