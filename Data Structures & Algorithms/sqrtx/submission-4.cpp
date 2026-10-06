class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;
            
            if (square <= x) {
                left = mid + 1;   // mid 有可能是答案，往右繼續找更大的可能
            } else {
                right = mid - 1;  // mid 太大，往左縮小範圍
            }
        }
        
        return right;
    }
};