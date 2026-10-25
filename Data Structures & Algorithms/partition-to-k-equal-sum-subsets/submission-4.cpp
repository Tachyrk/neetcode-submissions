class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k) return false;

        int total_sum = 0;
        for(int num : nums) total_sum += num;
        if(total_sum % k != 0) return false;
        int target = total_sum / k;

        sort(nums.rbegin(), nums.rend());
        vector<bool> is_used(n, false);
        auto back_track = [&](auto &self, int start, int level, int sum)->bool{
            if(level == k) return true;
            for(int i = start; i < n; i++){
                if(is_used[i]) continue;
                if(sum + nums[i] > target) continue;
                is_used[i] = true;
                if(sum + nums[i] == target){
                    if(self(self, 0, level + 1, 0)) return true;
                }else{
                    if(self(self, i + 1, level, sum + nums[i])) return true;
                }
                is_used[i] = false;
            }
            return false;
        };

        return back_track(back_track, 0, 0, 0);
    }
};