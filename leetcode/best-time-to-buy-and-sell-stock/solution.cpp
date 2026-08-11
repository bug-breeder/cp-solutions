class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int result = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);
            result = max(result, price - minPrice);
        }

        return result;
    }
};
