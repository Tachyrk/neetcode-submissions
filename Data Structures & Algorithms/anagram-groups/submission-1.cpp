class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        vector<vector<string>> ans;
        int index = 0;
        for(auto &s : strs){
            string freq(26, 0);
            for(char c : s){
                freq[c - 'a']++;
            }

            if(auto it = mp.find(freq); it != mp.end()){
                ans[it->second].push_back(s);
            }else{
                ans.push_back({s});
                mp[freq] = index++;
            }
        }

        return ans;
    }
};