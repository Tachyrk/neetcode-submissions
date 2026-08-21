class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int freq[26] = {0};
        int n = s.size();      
        int maximum; 
        for(int i = 0, left = 0; i < n; i++){
            freq[s[i] - 'A']++;
            maximum = max(maximum, freq[s[i] - 'A']);
            while(left < i && (i - left + 1 - maximum) > k){
                freq[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, i - left + 1);
        }

        return ans;
    }
};
