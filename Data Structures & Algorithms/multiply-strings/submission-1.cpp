class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int m = num1.size(), n = num2.size();
        vector<int> pos(m + n, 0);

        // 1. 從右往左遍歷，直接在 (i+j, i+j+1) 完成乘法與即時累加
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + pos[i + j + 1]; // 加上原本在該低位累積的值

                pos[i + j + 1] = sum % 10;     // 當前低位只留個位數
                pos[i + j] += sum / 10;         // 進位直接塞給高位
            }
        }

        // 2. 正序構建字串，一行過濾前導零
        string ans;
        for (int p : pos) {
            if (!(ans.empty() && p == 0)) { // 只要 ans 是空的，遇到的 0 就是前導零
                ans.push_back(p + '0');
            }
        }

        return ans;
    }
};
