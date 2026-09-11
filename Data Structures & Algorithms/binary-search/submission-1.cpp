class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0,  right = n - 1;

        while(left < right){
            int mid = left + (right - left) / 2;
            if(target > nums[mid]){
                left = mid + 1;
            }else{
                right = mid;
            }
        }

        return nums[left] == target ? left : -1;
    }
};
