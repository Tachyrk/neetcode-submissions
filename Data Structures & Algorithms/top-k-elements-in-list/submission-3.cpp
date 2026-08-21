class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto num : nums){
            mp[num]++;
        }

        priority_queue<pair<int, int>> q;
        for(auto &element : mp){
            q.push({element.second, element.first});
        }

        vector<int> ans(k);
        for(int i = 0; i < k; i++){
            ans[i] = q.top().second;
            q.pop();
        }

        return ans;
    }
};
