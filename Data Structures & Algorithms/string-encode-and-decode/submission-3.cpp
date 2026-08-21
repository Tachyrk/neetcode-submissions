class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(auto& str: strs){
            s +=to_string(str.size());
            s += '#';
            s += str;            
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0, n = s.size();
        while(i < n){
            int pos = s.find('#', i);
            int length = stoi(s.substr(i, pos - i));
            ans.push_back(s.substr(pos + 1, length));
            i = pos + length + 1;
        }

        return ans;
    }
};
