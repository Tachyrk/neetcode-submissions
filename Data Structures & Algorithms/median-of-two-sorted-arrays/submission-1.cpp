class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);

        int total_left = (m + n + 1) / 2;
        int left = 0, right = m;
        while(left <= right){
            int i = left + (right - left) / 2;
            int j = total_left - i;

            int L1 = (i == 0)? INT_MIN : nums1[i - 1];
            int L2 = (j == 0)? INT_MIN : nums2[j - 1];
            int R1 = (i == m)? INT_MAX : nums1[i];
            int R2 = (j == n)? INT_MAX : nums2[j];

            if(L1 <= R2 && L2 <= R1){                
                if((m + n) & 1){
                    return max(L1, L2);
                }
                return (max(L1, L2) + min(R1, R2)) / 2.0;
            }else if(L1 > R2){
                right = i - 1;
            }else{
                left = i + 1;
            }
        }

        return 0.0;
    }
};
