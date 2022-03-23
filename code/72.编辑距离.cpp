/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        // 定义dp的含义为将word1中i个字符转换成word2j个字符花费的最少操作数
        int m = word1.size();
        int n = word2.size();
        // 有一个字符串为空串
        if(n == 0 || m == 0) {
            return n == 0 ? m : n;
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // 两种大情况
        // 1. word1[i] == word2[j]
        //      dp[i][j] = dp[i - 1][j - 1]
        // 2. word1[i] != word2[j]
        //      dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1])
        
        // 边界情况初始化
        for(int i = 0; i < m + 1; ++i) {
            dp[i][0] = i;
        }
        for(int j = 0; j < n + 1; ++j) {
            dp[0][j] = j;
        }
        for(int i = 1; i < m + 1; ++i) {
            for(int j = 1; j < n + 1; ++j) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    int m = min(dp[i][j - 1], dp[i - 1][j]);
                    dp[i][j] = 1 + min(m, dp[i - 1][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

