class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> temp;
        temp.reserve(n);     

        bitset<8> mp;
        vector<vector<int>> ans;
        auto helper = [&](auto &self)->void{
            if(temp.size() == n){
                ans.push_back(temp);
                return;
            }

            for(int i = 0; i < n; i++){    
                if (mp[i]) continue;

                // 核心剪枝：同層中，如果相同的數前面那個還沒用過，跳過
                if (i > 0 && nums[i] == nums[i - 1] && !mp[i - 1]) continue;        
                
                mp.set(i);
                temp.push_back(nums[i]);
                self(self);
                temp.pop_back();
                mp.reset(i);                            
            }
            return;
        };

        helper(helper);
       
        return ans;
    }
};