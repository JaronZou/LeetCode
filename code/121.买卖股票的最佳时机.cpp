/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 0, k = 0;
        int ans = 0;
        while(k < prices.size()) {
            if(prices[k] > prices[j]) {
                j = k;
            }
            else if(prices[k] < prices[i]) {
                int profit = prices[j] - prices[i];
                ans = ans > prices[j] - prices[i] ? ans : profit;
                i = k;
                j = k;
            }
            ++k;
        }
        int profit = prices[j] - prices[i];
        ans = ans > prices[j] - prices[i] ? ans : profit;
        return ans;
    }

    // int maxProfit(vector<int>& prices) {

    // }
};
// @lc code=end

