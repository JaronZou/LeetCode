/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    // greedy
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 1;
        int ans = 0;
        while(j < prices.size()) {
            if(prices[j] < prices[j - 1]) {
                ans += prices[j - 1] - prices[i];
                i = j;
            }
            ++j;
        }
        ans += prices[j - 1] - prices[i];
        return ans;
    }
};
// @lc code=end

