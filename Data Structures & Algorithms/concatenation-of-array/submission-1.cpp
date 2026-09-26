class Solution {
public:
    vector<int> getConcatenation(const vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n); // 一次分配到位
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }
        return ans; // 享有編譯器 NRVO，零拷貝回傳
    }
};