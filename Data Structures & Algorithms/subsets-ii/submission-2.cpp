class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> temp;
        auto dfs = [&](auto &self, int start) ->void{
            ans.push_back(temp);
            for(int i = start; i < n; i++){
                if(i > start && nums[i] == nums[i - 1]) continue;
                temp.push_back(nums[i]);
                self(self, i + 1);
                temp.pop_back();
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};
