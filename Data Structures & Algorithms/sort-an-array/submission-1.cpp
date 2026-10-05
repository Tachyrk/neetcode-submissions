class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        auto quicksort = [&](auto &self, int start, int end)->void{
            if(start >= end) return;
            int mid = start + (end - start) / 2;
            int pivot = nums[mid];
            int it = start;
            int i = start;
            int gt = end;
            while(i <= gt){
                if(nums[i] < pivot){
                    swap(nums[it++], nums[i++]);
                }else if (nums[i] > pivot){
                    swap(nums[gt--], nums[i]);
                }else{
                    i++;
                }
            }
          
            self(self, start, it - 1);
            self(self, gt + 1, end);
        };

        int n = nums.size();
        quicksort(quicksort, 0, n - 1);
        return nums;
    }
};