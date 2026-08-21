class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto num : nums){
            mp[num]++;
        }

        vector<pair<int, int>> arr;
        arr.reserve(mp.size());        
        for(auto &element : mp){
            arr.push_back({element.second, element.first});
        }

        sort(arr.begin(), arr.end(), [&](const auto &a, const auto &b){
            return a.first > b.first;
        });
        vector<int> ans(k);
        for(int i = 0; i < k; i++){
            ans[i] = arr[i].second;            
        }

        return ans;
    }
};
