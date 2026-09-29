class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 0, cnt = 0;
        for (int x : nums) {
            if (cnt == 0) major = x;
            cnt += (x == major) ? 1 : -1;
        }
        return major;
    }
};