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
           
            //int remain = n - start + 1;
            //int need = k - idx;
            // n - start + 1 >= k - idx
            // n - (k - idx) + 1 >= start
            for(int i = start; i <= n - (k - idx) + 1; i++){
                temp[idx] = i;
                self(self, idx + 1, i + 1);
            }
        };

        backtrack(backtrack, 0, 1);
        return ans;
    }
};