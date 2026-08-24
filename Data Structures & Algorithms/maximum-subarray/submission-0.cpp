class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int temp = 0;
        for(int num : nums){
            temp += num;
            ans = max(ans, temp);
            if(temp < 0) temp = 0;
        }
        return ans;
    }
};
