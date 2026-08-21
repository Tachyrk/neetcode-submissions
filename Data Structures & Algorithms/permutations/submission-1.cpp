class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int valid = 0;
        vector<vector<int>> ans;
        vector<int> temp;
        auto dfs = [&](auto &self)->void{
            if(temp.size() == nums.size()){
                ans.push_back(temp);
                return;
            }
            for(int i = 0; i < nums.size(); i++){
                if(!(valid & (1 << i))){
                    valid |= (1 << i);
                    temp.push_back(nums[i]);
                    self(self);
                    valid &= ~(1 << i);
                    temp.pop_back();
                }
            }
        };
        dfs(dfs);
        return ans;
    }
};
