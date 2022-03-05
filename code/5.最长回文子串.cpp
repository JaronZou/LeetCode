/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        // 初始时，dp表中所有的点都为true。
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), true));
        int maxPalinLen = 1, palinIdx = 0;
        for(int i = 0; i < s.size() - 1; ++i) {
            // 检查j == i + 1时，s[i]和s[j]是否相等，这里的j用i + 1指代
            if(s[i] == s[i + 1]) {
                if(maxPalinLen < 2) {
                    maxPalinLen = 2;
                    palinIdx = i;
                }
            }
            // 不相等，dp[i][j]就为false
            else {
                dp[i][i + 1] = false;
            }
        }

        for(int i = 2; i < s.size(); ++i) {
            for(int j = 0; j < s.size() - i; ++j) {
                if(!dp[j + 1][j + i - 1]) {
                    dp[j][j + i] = false;
                }
                else if(s[j] != s[j + i]){
                    dp[j][j + i] = false;
                }
                else {
                    // 更新最长回文子串的长度和首字符索引
                    if(maxPalinLen < i + 1) {
                        maxPalinLen = i + 1;
                        palinIdx = j;
                    }
                }
            }
        }
        return s.substr(palinIdx, maxPalinLen);
    }
};
// @lc code=end

