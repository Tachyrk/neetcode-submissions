class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();
        vector<int> ans;
        ans.reserve(n + 1);
        int addone = 1;
        for(int i = n - 1; i >= 0; i--){
            int res = digits[i] + carry + addone;
            addone = 0;
            if(res == 10){
                res %= 10;
                carry = 1;
            }else{
                carry = 0;
            }
            ans.push_back(res);
        }
        if(carry) ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
