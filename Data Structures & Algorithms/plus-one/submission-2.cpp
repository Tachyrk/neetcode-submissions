class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits; // 沒有進位了，直接結束回傳！
            }
            digits[i] = 0; // 原本是 9，加 1 變 0，繼續向前進位
        }
        
        // 能走到這裡，表示原本全是 9 (例如 999 變成了 000)
        digits[0] = 1;
        digits.push_back(0); // 直接在尾端補 0，等價於前面插入 1，避免 O(N) 的 insert(begin)
        return digits;
    }
};