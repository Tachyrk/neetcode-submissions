class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        auto dfs = [&](auto& self, int start, int sum) ->void{
            if(sum == target){
                ans.push_back(temp);
                return;
            }

            for(int i = start; i < nums.size(); i++){
                if(sum + nums[i] <= target){
                    temp.push_back(nums[i]);
                    self(self, i, sum + nums[i]);
                    temp.pop_back();
                }
            }
            return;
        };

        dfs(dfs, 0 , 0);
        return ans;
    }
};
