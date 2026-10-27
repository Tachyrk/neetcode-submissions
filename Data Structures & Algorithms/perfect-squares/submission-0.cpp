class Solution {
public:
    int numSquares(int n) {
        static const vector<int> squares = []()->vector<int>{
            vector<int> temp;
            temp.reserve(101);
            for(int i = 1; i * i <= 10000; i++){
                temp.push_back(i * i);
            }
            return temp;
        }();

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int square : squares){
                if(i < square) break;
                if(dp[i - square] != INT_MAX);
                dp[i] = min(dp[i], dp[i - square] + 1);
            }
        }

        return dp[n];
    }
};