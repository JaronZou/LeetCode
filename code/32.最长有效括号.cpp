/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 1) {
            return 0;
        }
        // dp[i]的含义为以i结尾的有效匹配括号的长度
        // s[i] == '('
        //      dp[i] = 0
        // s[i] == ')'
        //      s[i - dp[i - 1] - 1] == '('
        //          dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2]
        //          前提是上面的下标都不越界
        //      下标发生越界或s[i - dp[i - 1] - 1] != '('
        //          dp[i] = 0
        vector<int> dp(s.size(), 0);
        int maxLen = 0;
        for(int i = 1; i < s.size(); ++i) {
            if(s[i] == ')') {
                int index = i - dp[i - 1] - 1;
                // index未发生越界且有s[index] == '(' && s[i] == ')'
                if(index >= 0 && s[index] == '(') {
                    dp[i] = dp[i - 1] + 2;
                    // 防止index - 1越界
                    if(index - 1 >= 0) {
                        dp[i] += dp[index - 1];
                    }
                }
                if(dp[i] > maxLen) {
                    maxLen = dp[i];
                }
            }
        }
        return maxLen;
    }
};
// @lc code=end

