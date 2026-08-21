class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        // 1. 預先排序，為極致剪枝做準備
        sort(nums.begin(), nums.end()); 

        auto dfs = [&](auto &self, int start, int sum) -> void {
            if(sum == target){
                ans.push_back(temp);
                return;
            }

            for(int i = start; i < nums.size(); i++){
                // 2. 提早結束：如果當前數字加進去已經超過 target，
                // 因為陣列有排序，後面的數字肯定也超過，直接 break 整個迴圈
                if(sum + nums[i] > target) {
                    break;
                }
                
                temp.push_back(nums[i]);
                self(self, i, sum + nums[i]);
                temp.pop_back();
            }
        };

        dfs(dfs, 0, 0);
        return ans;
    }
};