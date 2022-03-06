/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') {
            return 0;
        }
        if(s.size() == 1) {
            return 1;
        }
        // dp[i]的含义为当前来到s[i]字符有多少种解码方式
        // dp[0] = 1;
        // dp[1] = (s[0] == '1' || (s[0] == '2' && s[1] <= '6')) ? 2 : 1;
        // if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
        //      dp[i] = dp[i - 2] 
        // if(s[i] != '0')
        //      dp[i] += dp[i - 1]
        vector<int> dp(s.size(), 0);
        // 初始值
        dp[0] = 1;
        if(s[0] == '1' || (s[0] == '2' && s[1] <= '6')) {
            dp[1] = 1;
        }
        if(s[1] != '0') {
            dp[1] += 1;
        }
        for(int i = 2; i < s.size(); ++i) {
            // 10 ~ 26内的数字都可以一次解码两个数字
            if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                dp[i] = dp[i - 2];
            }
            // 当前数值不能为0，如果为0，那么只能进行一次解码两个数字
            if(s[i] != '0') {
                dp[i] += dp[i - 1];
            }
        }
        return dp[s.size() - 1];
    }
};
// @lc code=end

