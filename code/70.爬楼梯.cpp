/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    // int climbStairs(int n) {
    //     if(n <= 2) {
    //         return n;
    //     }
    //     // dp[i]的含义为跳到第i级台阶有dp[i - 1]种方法。
    //     // dp[i] = dp[i - 1] + dp[i - 2];
    //     vector<int> dp(n + 1, 0);
    //     dp[0] = 0;
    //     dp[1] = 1;
    //     dp[2] = 2;
    //     for(int i = 3; i < n + 1; ++i) {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }
    //     return dp[n];
    // }

    int climbStairs(int n) {
        if(n <= 2) {
            return n;
        }
        // 由于dp表中的值我们只需要使用 i - 1 项和 i - 2 项，因此设置两个变量保存即可
        int pre1 = 1, pre2 = 2;
        int result = 0;
        for(int i = 3; i < n + 1; ++i) {
            result = pre1 + pre2;
            pre1 = pre2;
            pre2 = result;
        }
        return result;
    }
};
// @lc code=end

