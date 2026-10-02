class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int priority[26] = {0};
        for(int i = 0; i < 26; i++){
            int idx = order[i] - 'a';
            priority[idx] = i;
        }

        auto is_less_or_equal = [&](const auto &w1, const auto &w2)->bool{
            int len = min(w1.size(), w2.size());
            int idx;
            for(idx = 0; idx < len; idx++){
                int p1 = priority[w1[idx] - 'a'];
                int p2 = priority[w2[idx] - 'a'];
                if(p1 > p2) return false;
                if(p2 > p1) return true;
            }
            return w1.size() <= w2.size();
        };

        int n = words.size();
        for(int i = 1; i < n; i++){
            if(is_less_or_equal(words[i - 1], words[i]) == false) return false;
        }

        return true;
    }
};