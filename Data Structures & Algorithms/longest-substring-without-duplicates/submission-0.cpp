class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int n = s.size();
        int ans = 0;
        for(int i = 0, left = 0; i < n; i++){
            freq[s[i]]++;
            while(left <= i && freq[s[i]] > 1){
                freq[s[left]]--;
                left++;
            }
            ans = max(ans, i - left + 1);
        }

        return ans;
    }
};
