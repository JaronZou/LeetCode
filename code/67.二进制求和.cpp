/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int carryBit = 0;
        int i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 && j >= 0) {
            int c1 = a[i] - '0', c2 = b[j] - '0';
            int curbit = c1 ^ c2 ^ carryBit;
            // 只要有两个或两个以上1，就进位
            carryBit = (c1 & c2) | (c1 & carryBit) | (c2 & carryBit);
            result.push_back(curbit == 1 ? '1' : '0');
            --i;
            --j;
        }
        string &remain = j < 0 ? a : b;
        int idx = j < 0 ? i : j;
        while(idx >= 0) {
            int c = remain[idx] - '0';
            int curbit = c ^ carryBit;
            carryBit = c & carryBit;
            result.push_back(curbit == 1 ? '1' : '0');
            --idx;
        }
        if(carryBit == 1) {
            result.push_back('1');
        }
        return {result.crbegin(), result.crend()};
    }
};
// @lc code=end

