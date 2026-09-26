class Solution {
public:
    void reverseString(vector<char>& s) {
        size_t n = s.size() - 1;
        size_t i = 0;
        while(i < n){
            swap(s[i], s[n]);
            i++;
            n--;
        }        
    }
};