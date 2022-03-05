/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), true));
        int maxPalinLen = 1, palinIdx = 0;
        for(int i = 0; i < s.size() - 1; ++i) {
            if(s[i] == s[i + 1]) {
                if(maxPalinLen < 2) {
                    maxPalinLen = 2;
                    palinIdx = i;
                }
            }
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

