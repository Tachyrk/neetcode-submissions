class Solution {
public:
    int numDecodings(string s) {
        //if(s[0] == '0') return 0;
        int dp1 = 1, dp2 = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            int temp = 0;
            int val = (s[i]) - '0';
            if(val != 0){
                //temp += 1;
                temp += dp1;
            }
            if(i > 0){
                val += (s[i - 1] - '0') * 10;
                if(val <= 26 && val >= 10){
                    temp += dp2;
                }
            }
            dp2 = dp1;
            dp1 = temp;
        }

        return dp1;
    }
};
