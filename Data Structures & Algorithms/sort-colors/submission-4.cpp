class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        for(int i = 0; i < n; i++){
            while(nums[i] != 1 && l <= i && i <= r){
                if(nums[i] == 0) swap(nums[i], nums[l++]);
                if(nums[i] == 2) swap(nums[i], nums[r--]);
            }         
        }
        return;
    }
};