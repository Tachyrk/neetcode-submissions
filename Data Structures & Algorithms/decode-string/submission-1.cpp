class Solution {
public:
    string decodeString(string s) {
        // 招式一：以 std::vector 取代 std::stack
        // std::stack 預設底層是 std::deque（分頁配置），改用 vector 具備記憶體連續性，
        // 且能透過 reserve() 預先鎖定空間，徹底消除動態擴容開銷。
        vector<int> count_st;
        vector<string> str_st;

        // 預估括號最大巢狀深度，預先配置 Stack 空間
        count_st.reserve(s.size() / 2);
        str_st.reserve(s.size() / 2);

        string curr_str = "";
        // 預先配置當前字串的初始容量，減少一般字元 push_back 觸發擴容
        curr_str.reserve(s.size());

        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                // 累積多位數倍數
                k = k * 10 + (c - '0');
            } 
            else if (c == '[') {
                // 進入新層級：將當前累計倍數與上一層字串推進 Stack
                count_st.push_back(k);
                
                // 使用 std::move 轉移字串所有權，避免複製整串字元
                str_st.push_back(std::move(curr_str));

                // 重設狀態準備收集當前括號內的字元
                k = 0;
                curr_str.clear();
            } 
            else if (c == ']') {
                // 離開當前層級：彈出該層的重複次數與上一層未完成字串
                int repeat_times = count_st.back();
                count_st.pop_back();

                string prev_str = std::move(str_st.back());
                str_st.pop_back();

                // 招式二：針對展開後的總長度精確執行 reserve
                // 新長度 = 上一層長度 + (當前括號內字串長度 * 重複倍數)
                size_t target_capacity = prev_str.size() + curr_str.size() * repeat_times;
                prev_str.reserve(target_capacity);

                // 在容量已足夠的前提下連續追加，保證為純記憶體拷貝（memcpy），零重分配
                while (repeat_times--) {
                    prev_str += curr_str;
                }

                // 將結算好的字串所有權轉移給 curr_str
                curr_str = std::move(prev_str);
            } 
            else {
                // 普通英文字母，直接推入當前緩衝區
                curr_str.push_back(c);
            }
        }

        return curr_str;
    }
};