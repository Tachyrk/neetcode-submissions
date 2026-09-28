class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int temp = 0;
        auto backtrack = [&](auto &self, int start)->void{
            ans += temp;
            if(start == n){
                return;
            }
            for(int i = start; i < n; i++){
                temp ^= nums[i];
                self(self, i + 1);
                temp ^= nums[i];
            }
            return;
        };
        backtrack(backtrack, 0);
        return ans;
    }
};