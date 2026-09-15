class Solution {
public:
    bool checkValidString(string s) {
        int c_min = 0, c_max = 0;
        for (char c : s) {
            if (c == '(') {
                c_min++;
                c_max++;
            } else if (c == ')') {
                c_min--;
                c_max--;
            } else { // '*'
                c_min--; // 當成 ')'
                c_max++; // 當成 '('
            }

            if (c_max < 0) return false; // 右括號過多
            c_min = max(c_min, 0);       // 下限不能小於 0
        }
        return c_min == 0;
    }
};