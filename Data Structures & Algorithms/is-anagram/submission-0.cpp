class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(n != m) return false;
        int freq_s[26] = {0}, freq_t[26] = {0};
        for(int i = 0; i < m; i++){
            freq_s[s[i] - 'a']++;
            freq_t[t[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(freq_s[i] != freq_t[i]) return false;
        }

        return true;
    }
};
