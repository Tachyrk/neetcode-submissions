class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        
        unordered_set<int> mp(nums.begin(), nums.end());
        for(auto num : mp){
            if(mp.find(num - 1) != mp.end()) continue;

            int current_num = num;
            int current_len = 0;
            while(mp.find(current_num) != mp.end()){
                current_num++;
                current_len++;
            }

            ans = max(ans, current_len);
        }

        return ans;
    }
};
