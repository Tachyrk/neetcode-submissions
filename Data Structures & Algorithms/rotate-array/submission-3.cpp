class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        auto manual_reverse = [&](int start, int end)->void{
            while(start < end){
                swap(nums[start++], nums[end--]);
            }
        };

        int K = k % n;
        manual_reverse(0, n - 1);
        manual_reverse(0, K - 1);
        manual_reverse(K, n - 1);
    }
};