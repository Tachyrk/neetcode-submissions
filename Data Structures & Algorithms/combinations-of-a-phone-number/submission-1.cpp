class Solution {
public:
    vector<string> keypad = {
        "", //Key 0
        "", //Key 1
        "abc", //Key 2
        "def", //Key 3
        "ghi", //Key 4
        "jkl", //Key 5
        "mno", //Key 6
        "pqrs", //Key 7
        "tuv", //Key 8
        "wxyz" //Key 9
    };
    vector<string> letterCombinations(string digits) {
        int n = digits.size();        
        vector<string> ans;
        if(!n) return ans; 
        string temp = "";
        auto dfs = [&](auto &self, int idx)->void{
            if(idx == digits.size()){
                ans.push_back(temp);
                return;
            }
            int num = digits[idx] - '0';
            for(int i = 0; i < keypad[num].size(); i++){
                temp += keypad[num][i];
                self(self, idx + 1);
                temp.pop_back();
            }
        };

        dfs(dfs, 0);
        return  ans;
    }
};
