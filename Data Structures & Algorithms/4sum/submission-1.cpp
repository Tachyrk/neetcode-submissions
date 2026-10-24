class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();        
        vector<vector<int>> ans;
        if(n < 4) return ans;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n - 2; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                long long need = (long long)target - nums[i] - nums[j];
                int l = j + 1, r = n - 1;
                while(l < r){
                    long long sum = (long long)nums[l] + nums[r];
                    if(sum == need){
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l < r && nums[l + 1] == nums[l]) l++;
                        while(l < r && nums[r - 1] == nums[r]) r--;
                        l++;
                        r--;
                    }else if(sum < need){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }

        return ans;
    }
};