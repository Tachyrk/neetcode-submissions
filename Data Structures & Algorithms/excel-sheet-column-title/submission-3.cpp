class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        int temp = columnNumber;
        while(temp){
            temp -= 1;
            ans.push_back(temp % 26 + 'A');
            temp /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};