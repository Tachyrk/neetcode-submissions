class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if (n < 4) return false;

        long long total_length = 0;
        int max_stick = 0;
        for (int x : matchsticks) {
            total_length += x;
            max_stick = max(max_stick, x);
        }

        if (total_length % 4 != 0) return false;
        int target = total_length / 4;
        if (max_stick > target) return false;

        // 剪枝 1：由大到小排序，大火柴先放才能提早引爆剪枝
        sort(matchsticks.rbegin(), matchsticks.rend());

        vector<bool> used(n, false);

        // cnt: 已湊齊的邊數, current: 當前邊累積長度, start_idx: 搜尋起點
        auto backtrack = [&](auto& self, int cnt, int current, int start_idx) -> bool {
            // 剪枝 2：湊齊 3 條邊，剩下的火柴總和必定剛好等於 target，直接回傳 true
            if (cnt == 3) return true;

            for (int i = start_idx; i < n; ++i) {
                if (used[i]) continue;
                if (current + matchsticks[i] > target) continue;

                used[i] = true;
                if (current + matchsticks[i] == target) {
                    // 當前邊滿了，開新邊：cnt + 1，current 重置為 0，start_idx 重置為 0
                    if (self(self, cnt + 1, 0, 0)) return true;
                } else {
                    // 同一條邊繼續湊：維持 cnt，start_idx 設為 i + 1（消除排列重複）
                    if (self(self, cnt, current + matchsticks[i], i + 1)) return true;
                }
                used[i] = false;

                // 剪枝 3：空邊放的第一根火柴就失敗，或湊滿目標的最後一根失敗，直接整條路判死
                if (current == 0 || current + matchsticks[i] == target) {
                    return false;
                }

                // 剪枝 4：跳過相同長度的火柴，避免重複無效嘗試
                while (i + 1 < n && matchsticks[i] == matchsticks[i + 1]) {
                    i++;
                }
            }

            return false;
        };

        return backtrack(backtrack, 0, 0, 0);
    }
};