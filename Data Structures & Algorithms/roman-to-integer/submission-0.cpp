class Solution {
public:    
    int romanToInt(string s) {
        static unordered_map<char, int> mp = [](){
            unordered_map<char, int> temp;
            temp['I'] = 1;
            temp['V'] = 5;
            temp['X'] = 10;
            temp['L'] = 50;
            temp['C'] = 100;
            temp['D'] = 500;
            temp['M'] = 1000;
            return temp;
        }();
        

        int ans = 0;
        int n = s.size();
        vector<char> st(n);
        int idx = 0;

        for(char c : s){
            while(idx > 0 && mp[st[idx - 1]] < mp[c]){
                ans -= mp[st[idx - 1]];
                idx--;
            }
            st[idx++] = c;            
        }

        for(int i = 0; i < idx; i++) ans += mp[st[i]];
        return ans;
    }
};