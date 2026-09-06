class Solution {
public:
    int reverse(int x) {
        bool sign = (x < 0);
        int ans = 0;
        int temp = abs(x);
        while(temp){
            if(ans >= 214748365)  return 0;
            ans = (ans * 10) + (temp % 10);
            temp /= 10;
        }

        return sign ? -1 * ans : ans;
    }
};
