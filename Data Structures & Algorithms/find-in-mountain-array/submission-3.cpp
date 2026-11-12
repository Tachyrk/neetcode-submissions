class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        // 1. 找峰值：只需比較 mid 與 mid + 1，每輪最多 2 次 get()
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int peak = l;

        // 2. 用方向係數 dir 合併上下坡搜尋（1 代表升序，-1 代表降序）
        auto binary_search = [&](int begin, int end, int dir) -> int {
            int t = target * dir;
            while (begin <= end) {
                int mid = begin + (end - begin) / 2;
                int val = mountainArr.get(mid) * dir;
                if (val == t) return mid;
                else if (val < t) begin = mid + 1;
                else end = mid - 1;
            }
            return -1;
        };

        int left_res = binary_search(0, peak, 1);
        if (left_res != -1) return left_res;
        return binary_search(peak + 1, n - 1, -1);
    }
};