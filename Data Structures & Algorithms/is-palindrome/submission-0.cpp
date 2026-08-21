class Solution {
public:
    bool checkvalid(char c){
        if((c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        (c >= '0' && c <= '9')) return true;
        return false;
    }
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;

        while(left < right){
            while(!checkvalid(s[left]))left++;
            while(!checkvalid(s[right]))right--;
            if(left >= right) break;

            if(s[left] >= 'A' && s[left] <= 'Z') s[left] = s[left] - 'A' + 'a';
            if(s[right] >= 'A' && s[right] <= 'Z') s[right] = s[right] - 'A' + 'a';
            if(s[left] != s[right]){               
                return false;
            }
            
            left++;
            right--;
        }

        return true;
    }
};
