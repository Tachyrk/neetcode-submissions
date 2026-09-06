class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        
        while (x != 0) {
            //因為正負最大最小一定是 21開頭 or -21 開頭， 翻轉後必定也是12 結尾，因此只要 > 4 就會很危險。
            // INT_MAX / 10 == 214748364
            // INT_MIN / 10 == -214748364
            if (ans > 214748364 || ans < -214748364) {
                return 0;
            }
            
            ans = ans * 10 + (x % 10);
            x /= 10;
        }

        return ans;
    }
};