class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long left = 0, right = 0;
        for(int num : nums){
            left = max(left, (long long)num);
            right += num;
        }

        auto try_split = [&](long long capacity)->int{
            int cnt = 1;
            long long sum = 0;
            for(int num : nums){
                sum += num;
                if(sum > capacity){
                    cnt++;
                    sum = num;
                }
            }
            return cnt;
        };

        while(left <= right){
            long long mid = left + (right - left) / 2;
            int res = try_split(mid);
            if(res <= k){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
};