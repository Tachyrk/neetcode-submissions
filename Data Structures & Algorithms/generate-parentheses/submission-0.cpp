class Solution {
public:
    vector<string> generateParenthesis(int n) {       
        string temp = "";
        vector<string> ans;
        auto dfs = [&](auto &self, int index, int leftcount, int rightcount) ->void{
            if(index == n * 2 && (leftcount == rightcount)){
                ans.push_back(temp);
            }
            if(leftcount < n){
                temp += '(';
                self(self, index + 1, leftcount + 1, rightcount);
                temp.pop_back();
            }

            if(rightcount < leftcount){
                temp += ')';
                self(self, index + 1, leftcount, rightcount + 1);
                temp.pop_back();
            }
        };

        dfs(dfs,0, 0, 0);
        return ans;
    }
};
