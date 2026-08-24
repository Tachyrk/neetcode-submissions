class Solution {
public:
    bool canJump(vector<int>& nums) {
        int MaxIdxCanReach = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i > MaxIdxCanReach) return false;
            MaxIdxCanReach = max(MaxIdxCanReach, i + nums[i]);
            if(MaxIdxCanReach >= n - 1) return true;
        }
        return false;
    }
};
