class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_cost = 1E9 + 7;
        int ans = 0;
        for(auto price : prices){
            ans = max(ans, price - min_cost);
            min_cost = min(min_cost, price);
        }

        return ans;
    }
};
