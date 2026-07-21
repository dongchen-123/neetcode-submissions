class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price = prices[0];
        int max_profit = 0;
        for (const auto& p : prices) {
            int profit = p - buy_price;
            if (p < buy_price) buy_price = p;
            else if (profit > max_profit) max_profit = profit;
        }
        return max_profit;
        
    }
};
