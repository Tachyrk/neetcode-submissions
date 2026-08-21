class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(), nums.end());
        return mp.size() < nums.size();
    }
};