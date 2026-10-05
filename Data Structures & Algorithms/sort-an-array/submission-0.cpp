class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        auto quicksort = [&](auto &self, int start, int end)->void{
            if(start >= end) return;
            int mid = start + (end - start) / 2;
            swap(nums[mid], nums[end]);
            int idx = start;
            int pivot = nums[end];
            for(int i = start; i < end; i++){
                if(nums[i] < pivot){
                    swap(nums[i], nums[idx]);
                    idx++;
                }
            }
            swap(nums[idx], nums[end]);
            self(self, start, idx - 1);
            self(self, idx + 1, end);
        };

        int n = nums.size();
        quicksort(quicksort, 0, n - 1);
        return nums;
    }
};