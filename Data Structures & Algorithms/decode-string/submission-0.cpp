class Solution {
public:
    string decodeString(string s) {
        string ans;
        int n = s.size();
        
        int idx;
        auto parser = [&](auto &self, int start)->string{
            string ans = "";
            int multi = 1;
            for(idx = start; idx < n; idx++){
                if(s[idx] == '['){
                    string res = self(self, idx + 1);                    
                    for(int i = 0; i < multi; i++){
                        ans += res;
                    }
                }else if(s[idx] == ']'){
                    return ans;
                }else{
                    if(s[idx] >= '0' && s[idx] <= '9'){
                        string temp = "";
                        while(s[idx] >= '0' && s[idx] <= '9'){
                            temp += s[idx];
                            idx++;
                        }
                        multi = stoi(temp);
                        idx--;
                    }else{
                        ans.push_back(s[idx]);
                    }
                }
            }
            return ans;
        };  
        return parser(parser, 0);
    }
};