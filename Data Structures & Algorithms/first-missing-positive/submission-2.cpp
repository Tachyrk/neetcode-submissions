class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 重點在 Positive  全是負數答案就是 1
        // 理想情況， array 數值應該要在 1~ n

        int n = nums.size();
        bool has_one = false;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                has_one = true;
            }
            if(nums[i] < 1 || nums[i] > n){
                nums[i] = 1;
            }
        }

        if(!has_one) return 1;
        for(int i = 0; i < n; i++){
            int val = abs(nums[i]) - 1;
            if(nums[val] > 0) nums[val] = -nums[val];
        }

        for(int i = 0; i < n; i++){            
            if(nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};