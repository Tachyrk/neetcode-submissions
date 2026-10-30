class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int st : stones) sum += st;
        int target = sum >> 1;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        int max_valid = 0;
        for(int st : stones){
            for(int i = target; i>= st; i--){
                if(dp[i - st] == true){
                    dp[i] = true;
                    max_valid = max(max_valid, i);
                }
            }
        }

        return sum - 2 * max_valid;
    }
};