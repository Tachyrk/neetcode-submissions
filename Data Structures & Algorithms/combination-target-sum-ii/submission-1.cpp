class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;

        auto dfs = [&](auto &self, int start, int sum) -> void{
            if(sum == target){
                ans.push_back(temp);
                return;
            }
            for(int i = start; i < candidates.size(); i++){
                if(sum + candidates[i] > target) break;
                if(i > start && candidates[i] == candidates[i - 1]) continue;
                temp.push_back(candidates[i]);
                self(self, i + 1, sum + candidates[i]);
                temp.pop_back();
            }
        };

        dfs(dfs, 0, 0);
        return ans;
    }
};
