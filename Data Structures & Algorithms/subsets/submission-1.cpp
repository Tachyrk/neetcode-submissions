class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int>& nums, int idx, int length, vector<int> temp){
        if(idx == length){
            ans.push_back(temp);
            return;
        }

        dfs(ans, nums, idx + 1, length, temp);
        temp.push_back(nums[idx]);
        dfs(ans, nums, idx + 1, length, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        /*ans.push_back({});        
        for(int i = 1; i < (1 << n); i++){
            vector<int> temp;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    temp.push_back(nums[j]);
                }
            }

            ans.push_back(temp);
        }*/

        dfs(ans, nums, 0, n, {});

        return ans;
    }
};
