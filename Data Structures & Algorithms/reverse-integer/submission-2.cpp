class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        
        while (x != 0) {
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