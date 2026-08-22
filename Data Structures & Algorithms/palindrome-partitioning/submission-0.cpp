class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        auto isPalindromic = [&](int start, int length)->bool{
            int end = start + length - 1;
            while(start < end){
                if(s[start] != s[end]) return false;
                start++;
                end--;
            }
            return true;
        };

        vector<vector<string>> ans;
        vector<string> temp;        
        auto dfs = [&](auto &self, int start)->void{
            if(start == n){               
                ans.push_back(temp);
                return;
            }
            
            for(int len = 1; len + start <= n; len++){
                if(isPalindromic(start, len)){
                    temp.push_back(s.substr(start, len));
                    self(self, start + len);
                    temp.pop_back();
                }
            }
        };

        dfs(dfs, 0);

        return ans;
    }
};
