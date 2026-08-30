class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 1;
        int record_left = 0, record_right = 0;
        int left, right;

        auto centered_scan = [&]()->void{
            while(left >= 0 && right < n){
                if(s[left] != s[right]) break;
                left--;
                right++;
            }
            if((right - left - 2) > (record_right - record_left)){
                record_right = right - 1;
                record_left = left + 1;
            }
        };
        for(int i = 0; i < n; i++){
            left = i, right = i;
            centered_scan();

            if(i < n - 1){
                left = i, right = i + 1;
                centered_scan();
            }
        }

        return s.substr(record_left, record_right - record_left + 1);
    }
};
