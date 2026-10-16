class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int write = 1; // 第一個元素 nums[0] 必然保留，從索引 1 開始寫入
        for (int read = 1; read < nums.size(); ++read) {
            if(nums[read] != nums[write - 1]){
                nums[write++] = nums[read];
            }
        }

        return write; // write 正好代表不重複元素的總數
    }
};