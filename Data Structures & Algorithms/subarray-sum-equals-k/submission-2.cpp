class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp.reserve(nums.size() + 1);
        
        mp[0] = 1;
        int ans = 0;
        int sum = 0;
        
        for (const int& num : nums) {
            sum += num;
            
            auto it = mp.find(sum - k);
            if (it != mp.end()) {
                ans += it->second;
            }
            
            mp[sum]++;
        }
        
        return ans;
    }
};