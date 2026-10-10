class Solution {
public:
    int GCD(int a, int b){
        return (b == 0) ? a : GCD(b, a % b);
    }
    string gcdOfStrings(string str1, string str2) {
        // 1. 驗證是否具備公約數性質
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        // 2. 長度必然是 gcd(n1, n2)
        return str1.substr(0, GCD(str1.size(), str2.size()));
    }
};