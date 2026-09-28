class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int bitwise_or = 0;
        for (int num : nums) {
            bitwise_or |= num;
        }
        // 乘以 2^(N-1)，即向左位移 (N - 1) 位
        return bitwise_or << (nums.size() - 1);
    }
};