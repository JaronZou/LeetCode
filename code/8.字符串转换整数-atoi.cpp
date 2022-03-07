/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int result = 0, preNum;
        // 跳过签到空白符
        int i = 0;
        while(i < s.size()) {
            if(s[i] != ' ') {
                break;
            }
            ++i;
        }
        // 符号标记
        bool isNegative = false;
        if(s[i] == '-') {
            isNegative = true;
            ++i;
        }
        else if(s[i] == '+') {
            ++i;
        }
        // 字符串转数字
        while(i < s.size()) {
            if(s[i] >= '0' && s[i] <= '9') {
                if(result > INT_MAX / 10 || result < INT_MIN / 10) {
                    return isNegative ? INT_MIN : INT_MAX;
                }
                result *= 10;
                int num = s[i] - '0';
                num = isNegative ? -num : num;
                // 判断下一次运算是否会发生溢出
                if(!isNegative && result > INT_MAX - num) {
                    return INT_MAX;
                }
                if(isNegative && result < INT_MIN - num) {
                    return INT_MIN;
                }
                result += num;
            }
            else {
                return result;
            }
            ++i;
        }
        return result;
    }
};
// @lc code=end

