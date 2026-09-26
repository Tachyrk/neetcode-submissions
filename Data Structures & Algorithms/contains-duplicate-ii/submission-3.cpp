class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){      
            if(mp.find(nums[i]) != mp.end()) return true;         
            mp.insert(nums[i]);
            if(i >= k){
                mp.erase(nums[i - k]);
            }                  
        }
        return false;
    }
};