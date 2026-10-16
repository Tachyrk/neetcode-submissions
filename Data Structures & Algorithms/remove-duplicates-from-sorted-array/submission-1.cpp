class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int write = 1; // 第一個元素 nums[0] 必然保留，從索引 1 開始寫入
        for (int read = 1; read < nums.size(); ++read) {
            // 只要發現快指針的數字與「當前最後一個有效數字」不同
            if (nums[read] != nums[write - 1]) {
                nums[write++] = nums[read]; // 直接向前覆蓋
            }
        }

        return write; // write 正好代表不重複元素的總數
    }
};