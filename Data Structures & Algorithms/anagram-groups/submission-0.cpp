class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> mp; // 修正 1：改用 unordered_map
        int index = 0;

        for(auto& s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            
            // 修正 2：拔掉 for 迴圈，直接使用 Hash Map 的 O(1) 尋找
            if(auto it = mp.find(temp); it != mp.end()){
                ans[it->second].push_back(s);
            } else {
                // 修正 3：加上大括號，把 s 裝進一個新的 vector 中再放入 ans
                ans.push_back({s});
                mp[temp] = index++;
            }
        }

        return ans;
    }
};