class Solution {
public:
    int getidx(char c){
        if(c >= 'a') return c - 'a' + 26;
        return c - 'A';
    }
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if(n < m) return "";
        int freq[52] = {0};
        int count = 0;
        for(auto c : t){
            int idx = getidx(c);
            if(freq[idx] == 0) count++;
            freq[idx]--;
        }

        string ans = "";
        for(int i = 0, left = 0; i < n; i++){
            int idx = getidx(s[i]);
            if(freq[idx] == -1){
                count--;
            }
            freq[idx]++;
            if(count == 0){
                int leftidx;
                while(count == 0){
                    leftidx = getidx(s[left]);
                    if(freq[leftidx] == 0){
                        count++;
                    }
                    freq[leftidx]--;
                    left++;
                }
                if(ans == ""){
                    ans = s.substr(left - 1, i - left + 2);
                }else{
                    if((i - left + 2) < ans.size()){
                        ans = s.substr(left - 1, i - left + 2);
                    }
                }
            }
        }

        return ans;
    }
};
