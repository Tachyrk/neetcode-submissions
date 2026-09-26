class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int diff_idx = 0;
        int len = INT_MAX;
        int n = strs.size();
        for(auto &s : strs) len = min(len, (int)s.size());

        if(len == 0) return "";
        string ans;
        ans.reserve(len);
        bool finish = false;
        for(diff_idx; diff_idx < len && !finish; diff_idx++){
            for(int i = 1; i < n; i++){
                if(strs[i][diff_idx] != strs[i - 1][diff_idx]){
                    finish = true;
                    break;
                }
            }
            if(!finish){
                ans.push_back(strs[0][diff_idx]);
            }
        }

        return ans;
    }
};