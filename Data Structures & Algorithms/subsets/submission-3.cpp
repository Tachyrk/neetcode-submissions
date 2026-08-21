class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int>& nums, int idx, int length, vector<int>& temp){ // 加上 &
        if(idx == length){
            ans.push_back(temp);
            return;
        }

        // 決策分支 1：不選 nums[idx]
        dfs(ans, nums, idx + 1, length, temp);

        // 決策分支 2：選 nums[idx]
        temp.push_back(nums[idx]);             // 做選擇
        dfs(ans, nums, idx + 1, length, temp); // 往下探索
        temp.pop_back();                       // 撤銷選擇 (Backtrack) 👈 這是關鍵！
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp; // 在外面宣告好，全程共用這一個
        
        dfs(ans, nums, 0, n, temp);

        return ans;
    }
};