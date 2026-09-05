class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            res ^= i ^ nums[i];
        }
        return res;*/

        int n = nums.size();
        int miss = 0;
        // 第一階段：真的把每個人都送回該去的位置（只要換回來的還不是主人，就繼續換）
        for (int i = 0; i < n; i++) {
            while (nums[i] < n && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
            while(miss < n && nums[miss] == miss){
                miss++;
            }
        }
        return miss;
    }
};