class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //maxSubarraysum in boundary -> direct find it
        //maxSubarraysum cross boundary -> find minSubarraysum -> totalsum - minSubarraysum
        long long total = 0;
        int n = nums.size();
        int maxcurrent = 0;
        int maxSubarraySum = INT_MIN;
        int mincurrent = 0;
        int minSubarraySum = INT_MAX;
        for(int i = 0; i < n; i++){
            total += nums[i];
            maxcurrent += nums[i];
            mincurrent += nums[i];
            maxSubarraySum = max(maxSubarraySum, maxcurrent);
            minSubarraySum = min(minSubarraySum, mincurrent);
            if(maxcurrent < 0) maxcurrent = 0;
            if(mincurrent > 0) mincurrent = 0;
        }
        if(maxSubarraySum > 0){
            return max(maxSubarraySum, (int)(total - minSubarraySum));
        }else{
            return maxSubarraySum;
        }        
    }
};