class Solution {
public:
    string addBinary(string a, string b) {     
        string ans;
        int m = a.size(), n = b.size();
        int i = m - 1, j = n - 1;
        ans.reserve(max(m,n) + 1);
        int carry = 0;
        while(i >= 0 || j >= 0 || carry){
            if(i >= 0) carry += (int)(a[i] - '0');
            if(j >= 0) carry += (int)(b[j] - '0');

            ans.push_back(carry % 2 + '0');
            carry >>= 1;
            i--;
            j--;
        }      
        reverse(ans.begin(), ans.end());
        return ans;
    }
};