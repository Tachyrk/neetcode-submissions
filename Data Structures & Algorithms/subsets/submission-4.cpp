class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(nums, 0, current, ans);
        return ans;
    }

private:
    void backtrack(const vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& ans) {
        // 走到任何一個節點，都代表一個合法的子集，直接收集起來
        // (空集合會在第一次呼叫、start 為 0 時被加入)
        ans.push_back(current);

        // 從 start 索引開始往後做選擇
        for (int i = start; i < nums.size(); i++) {
            
            // 1. 做選擇 (Choose)：將當前元素加入
            current.push_back(nums[i]);
            
            // 2. 往下探索 (Explore)：遞迴處理下一個位置 i + 1
            backtrack(nums, i + 1, current, ans);
            
            // 3. 撤銷選擇 (Unchoose / Backtrack)：把剛剛加入的元素吐出來，回到乾淨的狀態
            current.pop_back();
        }
    }
};