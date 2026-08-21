class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for(int i = 0; i < n - 2; i++){
            // 優化 1：如果最小的數已經大於 0，後面的數相加絕對不可能等於 0，直接提早結束
            if (nums[i] > 0) break;
            
            // 優化 2：寫在迴圈開頭的去重，閱讀上更直觀，避免與 for 迴圈的 i++ 產生混淆
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int j = i + 1;
            int k = n - 1;
            
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                
                if(sum == 0){                   
                    ans.push_back({nums[i], nums[j], nums[k]});
                    // 跳過 j 和 k 的重複元素
                    while(j < k && nums[j] == nums[j + 1]) j++;
                    while(j < k && nums[k] == nums[k - 1]) k--;
                    j++;
                    k--;
                } else if(sum > 0){
                    k--; // 總和太大，右指標往左移
                } else {
                    j++; // 總和太小，左指標往右移
                }
            }
        }
        return ans;
    }
};