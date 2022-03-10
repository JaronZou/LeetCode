/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    // int m = s.size();
    // int n = t.size();
    // s[i] != t[j]
    //      dp[i][j] = dp[i + 1][j]
    // s[i] == s[j]
    //      dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j]
    // 初始值
    // m - j > n - i 
    //      dp[i][j] = 0
    // dp[n - 1][m - 1] = s[n - 1] == t[m - 1] ? 1 : 0
    // dp[i][m - 1] = s[i] == s[m - 1] ? 1 + dp[i][m - 1] : dp[i][m - 1]
    int numDistinct(string s, string t) {
        if(s.size() < t.size()) {
            return 0;
        }
        // dp[i][j]的含义是s[i:]的子序列中串t[j:]出现的次数有多少
        vector<vector<unsigned int>> dp(s.size() + 1, vector<unsigned int>(t.size() + 1, 0));
        int m = s.size();
        int n = t.size();
        for(int i = 0; i < m + 1; ++i) {
            dp[i][n] = 1;
        }
        for(int i = m - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                dp[i][j] = dp[i + 1][j];
                if(s[i] == t[j]) {
                    dp[i][j] += dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

