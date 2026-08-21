class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = h;

        auto CalNeedTime = [&](int k) -> bool{
            long long ans = 0;
            for(auto pile : piles){
                ans += (long long)pile / k;
                if(pile % k != 0){
                    ans += 1;
                }
            }
            return ans <= h;
        };

        int left = 1, right = 1000000000;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(CalNeedTime(mid)){
                right = mid - 1;                
            }else{
                left = mid + 1;
            }
        }

        return left;
    }
};
