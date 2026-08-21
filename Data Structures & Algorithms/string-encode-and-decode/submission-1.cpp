class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(auto& str: strs){
            s = s + to_string(str.size());
            s = s + '#';
            s = s + str;            
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0, begin = 0, length, n = s.size();
        while(i < n){
            if(s[i] == '#'){
                length = stoi(s.substr(begin, i - begin));
                ans.push_back(s.substr(i + 1, length));
                i = i + length + 1;
                begin = i;
            }
            i++;
        }

        return ans;
    }
};
