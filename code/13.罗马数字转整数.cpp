/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    // int romanToInt(string s) {
    //     unordered_map<char, int> romVal = {
    //         {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    //     };
    //     int result = 0, i = 0;
    //     while(i < s.length()) {
    //         if(s.length() - i >= 2) {
    //             if(s[i] == 'C' && s[i + 1] == 'M') {
    //                 result += 900;
    //                 i += 2;
    //             }
    //             else if(s[i] == 'X' && s[i + 1] == 'C') {
    //                 result += 90;
    //                 i += 2;
    //             }
    //             else if(s[i] == 'I' && s[i + 1] == 'X') {
    //                 result += 9;
    //                 i += 2;
    //             }
    //             else if(s[i] == 'C' && s[i + 1] == 'D') {
    //                 result += 400;
    //                 i += 2;
    //             }
    //             else if(s[i] == 'X' && s[i + 1] == 'L') {
    //                 result += 40;
    //                 i += 2;
    //             }
    //             else if(s[i] == 'I' && s[i + 1] == 'V') {
    //                 result += 4;
    //                 i += 2;
    //             }
    //             else {
    //                 result += romVal[s[i]];
    //                 ++i;
    //             }
    //         }
    //         else {
    //             result += romVal[s[i]];
    //             ++i;
    //         }
    //     }
    //     return result;
    // }

    int romanToInt(string s) {
        unordered_map<char, int> romVal = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int result = 0;
        for(int i = 0; i < s.size(); ++i) {
            int cur = romVal[s[i]];
            // 下一个数比当前这个数大，那么就减去当前这个数
            if(i < s.size() - 1 && romVal[s[i + 1]] > cur) {
                result -= cur;
            }
            // 否则就加上当前这个数
            else {
                result += cur;
            }
        }
        return result;
    }
};
// @lc code=end

