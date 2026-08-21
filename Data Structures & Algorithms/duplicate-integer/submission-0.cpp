class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mp;
        for(int num : nums){
            if(mp.find(num) != mp.end()){
                return true;
            }
            mp.insert(num);
        }

        return false;
    }
};