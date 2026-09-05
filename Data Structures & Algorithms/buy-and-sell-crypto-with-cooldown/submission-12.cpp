class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int held = -prices[0]; // 第 0 天買入
        int sold = 0;          // 第 0 天不可能賣出
        int rest = 0;          // 第 0 天觀望

        for (int price : prices) {
            int prev_sold = sold;
            sold = held + price;
            held = max(held, rest - price);
            rest = max(rest, prev_sold);
        }

        return max(sold, rest);
    }
};