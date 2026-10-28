class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (right > left) {
            right &= (right - 1); // 抹除 right 最低位的 1
        }
        return right;
    }
};