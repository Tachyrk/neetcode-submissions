class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
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

        return ans;
    }
};
