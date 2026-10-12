class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0;
        for (int w : weights) {
            l = max(l, w);  // 下界：最大單件重量
            r += w;         // 上界：所有重量總和
        }

        auto canShip = [&](int capacity) -> bool {
            int need_days = 1;
            int current_weight = 0;

            for (int w : weights) {
                if (current_weight + w > capacity) {
                    need_days++;
                    current_weight = w;
                    // 提早剪枝：天數超標就不用繼續算了
                    if (need_days > days) return false;
                } else {
                    current_weight += w;
                }
            }
            return true;
        };

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canShip(mid)) {
                r = mid - 1; // 容量夠，往左找更小的可能
            } else {
                l = mid + 1; // 容量不夠，往右加大
            }
        }

        return l;
    }
};