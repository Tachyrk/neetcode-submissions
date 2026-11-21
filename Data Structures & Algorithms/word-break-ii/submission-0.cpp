class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();           

        unordered_set<string> mp;
        int max_word_size = 0;
        for(string &word : wordDict){
            mp.insert(word);
            max_word_size = max(max_word_size, (int)word.size());
        }

        vector<string> ans;
        vector<string> temp;
        temp.reserve(n);
        auto backtrack = [&](auto &self, int start)->void{
            if(start == n){
                string str;
                str.reserve(n + temp.size());
                for(int j = 0; j < temp.size(); j++){
                    str += temp[j];
                    str += " ";
                }
                str.pop_back();
                ans.push_back(str);
                return;
            }
            for(int i = start; i < n; i++){
                if(i - start > max_word_size) break;
                string sub = s.substr(start, i - start + 1);
                if(mp.find(sub) != mp.end()){
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