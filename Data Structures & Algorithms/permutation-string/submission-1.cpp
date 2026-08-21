class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n > m) return false;
        int freq[26] = {0};
        for(auto c : s1){
            freq[c - 'a']--;
        }

        for(int i = 0, left = 0; i < m; i++){
            freq[s2[i] - 'a']++;
            while(freq[s2[i] - 'a'] > 0){
                freq[s2[left] - 'a']--;
                left++;
            }

            if((i - left + 1) == n) return true;
        }
        return false;
    }
};
