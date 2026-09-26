class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(int idx = 0; idx < strs[0].size(); idx++){
            char c = strs[0][idx];
            for(int j = 1; j < strs.size(); j++){
                if(idx == strs[j].size() || strs[j][idx] != c){
                    return strs[0].substr(0, idx);
                }
            }
        }

        return strs[0];
    }
};