class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> temp;
        temp.reserve(n);

        bitset<8> mp;

        set<vector<int>> record;
        vector<vector<int>> ans;
        auto helper = [&](auto &self)->void{
            if(temp.size() == n){
                record.insert(temp);
                return;
            }

            for(int i = 0; i < n; i++){               
                if(!mp[i]){
                    mp.set(i);
                    temp.push_back(nums[i]);
                    self(self);
                    temp.pop_back();
                    mp.reset(i);
                }               
            }
            return;
        };

        helper(helper);

        for(auto &element : record) ans.push_back(element);
        return ans;
    }
};