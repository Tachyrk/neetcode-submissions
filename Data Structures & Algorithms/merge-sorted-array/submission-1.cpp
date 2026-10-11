class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m - 1, idx2 = n - 1, k = m + n - 1;

        // 只要 nums2 還沒填完就繼續；一旦 nums2 填完，nums1 剩下的原位不動直接收工
        while (idx2 >= 0) {
            if (idx1 >= 0 && nums1[idx1] > nums2[idx2]) {
                nums1[k--] = nums1[idx1--];
            } else {
                nums1[k--] = nums2[idx2--];
            }
        }
    }
};