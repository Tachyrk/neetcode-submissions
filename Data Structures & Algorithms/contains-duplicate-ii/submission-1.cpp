class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            if(i > k){
                mp[nums[i - k - 1]]--;
            }
            if(mp[nums[i]] > 1) return true;            
        }
        return false;
    }
};