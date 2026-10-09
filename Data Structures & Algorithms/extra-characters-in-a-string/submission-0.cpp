class Solution {
public:
    struct TRIE{
        TRIE *child[26] = {}; // 加上 = {}，全部指標預設為 nullptr
        int isEnd;
        TRIE(){
            isEnd = 0;
            
        }
        ~TRIE(){
            for(int i = 0; i < 26; i++){
                delete child[i];
            }
        }
    };
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
       
        TRIE *root = new TRIE();
        auto build_TRIE = [&](string &str)->void{
            TRIE *current = root;
            for(int i = 0; i < str.size(); i++){
                int idx = str[i] - 'a';                
                if(current->child[idx] == nullptr){
                    current->child[idx] = new TRIE();
                }
                current = current->child[idx];
            }
            current->isEnd = str.size();
        };

        // 照你的 search 設計，只修復內部的 3 個小地方
        auto search = [&](int start_idx) -> void {
            TRIE *current = root;
            for (int i = start_idx; i < s.size(); i++) {
                int c = s[i] - 'a'; // 1. 改名避免撞名，且正確取 s[i]

                if (current->child[c] == nullptr) {
                    return; // 字典樹無此外綴，直接中止
                }
                current = current->child[c]; // 2. 先往下走

                if (current->isEnd) { // 3. 走到節點後才檢查是不是單字
                    // start_idx + isEnd 正好是覆蓋到的長度，去掉原本多加的 + 1
                    dp[start_idx + current->isEnd] = min(dp[start_idx], dp[start_idx + current->isEnd]);
                }
            }
        };

        for(auto &dict : dictionary) build_TRIE(dict);
        
        for(int i = 0; i < n; i++){
            search(i);
            dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
        }

        return dp[n];
    }
};