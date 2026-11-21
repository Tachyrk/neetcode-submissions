class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string_view> mp;
        mp.reserve(wordDict.size());

        size_t max_word_size = 0;
        for (const string& word : wordDict) {
            mp.insert(word);
            max_word_size = max(max_word_size, word.size());
        }

        string_view sv(s);
        vector<string> ans;
        vector<string_view> temp;
        temp.reserve(n);

        auto backtrack = [&](auto& self, int start) -> void {
            if (start == n) {
                string str;
                str.reserve(n + temp.size());
                for (string_view w : temp) {
                    str += w;
                    str += ' ';
                }
                str.pop_back();
                ans.push_back(std::move(str));
                return;
            }
            for (int i = start; i < n; ++i) {
                size_t len = i - start + 1;
                if (len > max_word_size) break;
                string_view sub = sv.substr(start, len);
                if (mp.contains(sub)) {
                    temp.push_back(sub);
                    self(self, i + 1);
                    temp.pop_back();
                }
            }
        };

        backtrack(backtrack, 0);
        return ans;
    }
};