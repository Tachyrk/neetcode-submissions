class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp(k, 0);

        auto backtrack = [&](auto &self, int idx, int start) -> void {
            if(idx == k){
                ans.push_back(temp);
                return;
            }

            // 剪枝：剩餘數字若不足以湊滿 k 個，直接終止迴圈
            int max_start = n - (k - idx) + 1;
            for(int i = start; i <= max_start; i++){
                temp[idx] = i;
                self(self, idx + 1, i + 1);
            }
        };

        backtrack(backtrack, 0, 1);
        return ans;
    }
};