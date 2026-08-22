/*class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        auto isPalindromic = [&](int start, int length)->bool{
            int end = start + length - 1;
            while(start < end){
                if(s[start] != s[end]) return false;
                start++;
                end--;
            }
            return true;
        };

        vector<vector<string>> ans;
        vector<string> temp;        
        auto dfs = [&](auto &self, int start)->void{
            if(start == n){               
                ans.push_back(temp);
                return;
            }
            
            for(int len = 1; len + start <= n; len++){
                if(isPalindromic(start, len)){
                    temp.push_back(s.substr(start, len));
                    self(self, start + len);
                    temp.pop_back();
                }
            }
        };

        dfs(dfs, 0);

        return ans;
    }
};*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        
        // 1. 建立 DP 表：dp[i][j] 代表 s[i...j] 是否為迴文
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        // 由下往上、由左往右建表 (確保 dp[i+1][j-1] 已經被算過)
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                // 如果頭尾字元一樣，且「長度 <= 3」或「中間夾的字串也是迴文」
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }

        vector<vector<string>> ans;
        vector<string> temp;        
        
        // 2. DFS 保持原本優雅的架構，只是把 isPalindromic 換成查表
        auto dfs = [&](auto &self, int start) -> void {
            if(start == n){               
                ans.push_back(temp);
                return;
            }
            
            // 這裡改用終點 end 來枚舉，配合 dp[start][end] 的查表習慣
            for(int end = start; end < n; end++){
                // 極速 O(1) 查表！
                if(dp[start][end]){
                    temp.push_back(s.substr(start, end - start + 1));
                    self(self, end + 1);
                    temp.pop_back();
                }
            }
        };

        dfs(dfs, 0);
        return ans;
    }
};
