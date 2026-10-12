class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1, r = 10000000;    
        for(int w : weights) l = max(l, w);

        auto check = [&](int capacity)->int{
            int ans = 1;
            int accumulate = 0;
            for(int w : weights){
                if(accumulate + w > capacity){
                    ans++;
                    accumulate = w;
                }else{
                    accumulate += w;
                }
            }

            return ans;
        };

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(check(mid) <= days){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return l;
    }
};