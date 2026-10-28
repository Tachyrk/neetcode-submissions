class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long base = 1;
        while(base <= left) base <<= 1;
        if(base < right) return 0;

        long long ans = left;      
        for(int i = left + 1; i <= right; i++) ans &= i;
        return ans;
    }
};