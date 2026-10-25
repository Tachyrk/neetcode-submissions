class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) return false;

        int total_sum = 0;
        for (int num : nums) total_sum += num;
        if (total_sum % k != 0) return false;
        int target = total_sum / k;

        // 1. 降序排序：先放大的元素，能大幅減少回溯分支
        sort(nums.rbegin(), nums.rend());
        if (nums[0] > target) return false; // 最大值大於目標，直接無解

        vector<bool> is_used(n, false);

        auto back_track = [&](auto &self, int start, int level, int sum) -> bool {
            // 如果已經成功填滿 k - 1 個桶，最後一個桶的總和必然等於 target
            if (level == k - 1) return true;

            for (int i = start; i < n; i++) {
                if (is_used[i]) continue;
                if (sum + nums[i] > target) continue;

                // 剪枝 3：跳過相鄰重複數字
                if (i > start && nums[i] == nums[i - 1] && !is_used[i - 1]) continue;

                is_used[i] = true;
                
                if (sum + nums[i] == target) {
                    // 當前桶滿了，從第 0 格開始找下一個桶 (level + 1, sum = 0)
                    if (self(self, 0, level + 1, 0)) return true;
                } else {
                    // 繼續填當前桶
                    if (self(self, i + 1, level, sum + nums[i])) return true;
                }

                is_used[i] = false; // 還原狀態

                // -------------------------------------------------------------
                // 這就是你記憶中的神級剪枝！
                // 1. sum == 0: 作為新桶的第一個元素失敗 -> 其他更小的數字也不用試了
                // 2. sum + nums[i] == target: 作為最後一個把桶填滿的元素失敗 -> 也不用用碎數字替換
                // -------------------------------------------------------------
                if (sum == 0 || sum + nums[i] == target) {
                    break;
                }
            }
            return false;
        };

        return back_track(back_track, 0, 0, 0);
    }
};