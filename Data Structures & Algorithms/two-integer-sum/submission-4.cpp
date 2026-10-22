class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            int need_num = target - nums[i];
            if(auto it = mp.find(need_num) ; it != mp.end()){
                return {it->second, i};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};
