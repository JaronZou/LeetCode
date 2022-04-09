/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
public:
    // 模拟26进制转换为10进制
    string convertToTitle(int columnNumber) {
        string ans;
        int exp = 0;
        while(columnNumber != 0) {
            // 1 ~ 26 % 26 --> 1 ~ 26
            char ch = (columnNumber - 1) % 26 + 1;
            // 下面两部操作与26进制转换为10进制无异
            columnNumber -= ch * pow(26, exp);
            columnNumber /= 26;
            ans.push_back(ch + 64);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

