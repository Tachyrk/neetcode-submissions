class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //第一次用 BIT 做，挺有成就感的。
        /*int maximum = INT_MIN;
        int minimum = INT_MAX;
        for(int num : nums){
            maximum = max(maximum, num);
            minimum = min(minimum, num);
        }
        vector<int> BIT(maximum - minimum + 2, INT_MIN);

        auto update = [&](int idx, int val)->void{
            int current = idx;
            while(current < maximum - minimum + 2){
                BIT[current] = max(BIT[current], val);
                current += (current & (-current));
            }           
        };
        auto inquery = [&](int idx)->int{
            int current = idx;
            int ans = BIT[current];
            while(current > 0){
                ans = max(BIT[current], ans);
                current -= (current & (-current));
            }           
            return ans;
        };

        int ans = 1;       
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int idx = nums[i] - minimum + 1;
            int res = inquery(idx - 1);
            if(res == INT_MIN){
                update(idx, 1);
            }else{
                update(idx, res + 1);
                ans = max(ans, res + 1);
            }
        }

        return ans;*/

        int n = nums.size();
        vector<int> tails;
        for(int i = 0; i < n; i++){          
            auto it = lower_bound(tails.begin(), tails.end(), nums[i]);
            if(it == tails.end()){
                tails.push_back(nums[i]);
            }              
            else{
                *it = nums[i];
            }                             
        }
        
        return tails.size();
    }
};
