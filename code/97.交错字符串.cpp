/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // dp[i][j]定义为s1长度为i的前缀与s2长度为j的前缀是否能形成
        // 长度为i + j的s3的前缀
        // 考虑s3的第i + j - 1位置的字符来自哪里
        // 1. 来自s1
        // 2. 来自s2
        // dp[i][j] = (s3[i + j - 1] == s1[i] && dp[i - 1][j]) ||  
        //            (s3[i + j - 1] == s2[j] && dp[i][j - 1])
        int m = s1.size(), n = s2.size(), k = s3.size();
        if(m + n != k) {
            return false;
        }
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        // 初始化
        dp[0][0] = true;
        for(int i = 1; i <= m; ++i) {
            dp[i][0] = s3[i - 1] == s1[i - 1] && dp[i - 1][0];
        }
        for(int i = 1; i <= n; ++i) {
            dp[0][i] = s3[i - 1] == s2[i - 1] && dp[0][i - 1];
        }
        // dp表的构建
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                dp[i][j] = (s3[i + j - 1] == s1[i - 1] && dp[i - 1][j]) ||
                           (s3[i + j - 1] == s2[j - 1] && dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

