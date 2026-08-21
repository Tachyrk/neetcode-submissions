class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const auto& s : tokens) {
            // 長度為 1 且不是數字的情況，就是運算符
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                
                if (s == "+") st.push(num1 + num2);
                else if (s == "-") st.push(num1 - num2);
                else if (s == "*") st.push(num1 * num2);
                else if (s == "/") st.push(num1 / num2);
            } else {
                // 是數字（包含正負數）
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};