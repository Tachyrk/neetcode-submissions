class Solution {
public:
    vector<int> getConcatenation(const vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size() * 2); // 預先劃位，杜絕動態擴容開銷
        ans.insert(ans.end(), nums.begin(), nums.end());
        ans.insert(ans.end(), nums.begin(), nums.end());
        return ans; // NRVO 零拷貝回傳
    }
};