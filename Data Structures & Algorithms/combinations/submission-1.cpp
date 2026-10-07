class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;

        vector<int> temp(k, 0);
        //temp.reserve(k);
        auto backtrack = [&](auto &self, int idx, int start){
            if(idx == k){
                ans.push_back(temp);
                return;
            }

            for(int i = start; i <= n; i++){
                temp[idx] = i;
                //temp.push_back(i);
                self(self, idx + 1, i + 1);
                //temp.pop_back();
            }
        };

        backtrack(backtrack, 0, 1);
        return ans;
    }
};