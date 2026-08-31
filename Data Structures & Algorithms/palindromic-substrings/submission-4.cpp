class Solution {
public:
    int countSubstrings(string s) {
        /*int ans = 0;
        int n = s.size();
        int left, right;
        auto centered_scan = [&]()->int{
            int cnt = 0;
            while(left >= 0 && right < n){
                if(s[left] != s[right]) break;
                cnt++;
                left--;
                right++;
            }            
            return cnt;
        };

        for(int i = 0; i < n; i++){
            left = i;
            right = i;
            ans += centered_scan();

            if(i < n - 1){
                left = i;
                right = i + 1;
                ans += centered_scan();
            }
        }

        return ans;*/
        int n = s.size();
        int ans = 0;
        
        // dp[i][j] 代表子字串 s[i...j] 是否為迴文
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // 注意：i 必須從後往前遍歷，這樣計算 dp[i][j] 時，
        // 所依賴的 dp[i+1][j-1] (即內層子字串) 才會已經被計算過。
        for (int i = n - 1; i >= 0; i--) {
            // j 從 i 開始往後遍歷 (確保 j >= i，也就是合理的子字串區間)
            for (int j = i; j < n; j++) {
                
                // 判斷 s[i...j] 是否為迴文的條件：
                // 1. 首尾字元相同：s[i] == s[j]
                // 2. 滿足上述條件下，如果字串長度 <= 3 (即 j - i <= 2)，必然是迴文 
                //    (例如 "a", "aa", "aba")
                // 3. 或者去掉首尾後的內部字串也是迴文 (dp[i + 1][j - 1] == true)
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    ans++;
                }
            }
        }

        return ans;
    }
};
