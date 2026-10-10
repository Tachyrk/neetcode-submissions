class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        if(n1 < n2) return gcdOfStrings(str2, str1);

        for(int i = 0; i < n2; i++){
            if(str1[i] != str2[i]) return "";
        }

        for(int i = 0; i < n2; i++){
            int len = n2 - i;
            if(n1 % len != 0) continue;
            if(n2 % len != 0) continue;
            string gcd_str = str2.substr(0, n2 - i);
            string s = "";
            while(s.size() < n1) s += gcd_str;
            if(s == str1) return gcd_str;
        }
        return "";
    }
};