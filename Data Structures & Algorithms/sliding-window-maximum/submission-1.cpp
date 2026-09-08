class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            if(i >= k){
                 mp[nums[i - k]]--;
                 if(mp[nums[i - k]] == 0) mp.erase(nums[i - k]);
            }
            if(i >= k - 1){
                auto it = prev(mp.end());
                ans.push_back(it->first);
            }
        }

        return ans;
    }
};
