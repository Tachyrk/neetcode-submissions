class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int ans = 1;
        
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            if(mp.find(nums[i]) != mp.end()) continue;
            int left_bound = 0;            
            if(mp.find(nums[i] - 1) != mp.end()){
                left_bound = mp[nums[i] - 1];
            }
            int right_bound = 0;
            if(mp.find(nums[i] + 1) != mp.end()){
                right_bound = mp[nums[i] + 1];
            }

            mp[nums[i]] = 1 + left_bound + right_bound;
            mp[nums[i] - left_bound] = mp[nums[i]];
            mp[nums[i] + right_bound] = mp[nums[i]];
            ans = max(ans, mp[nums[i]]);
        }
       
        return ans;
    }
};
