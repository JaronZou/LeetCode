/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start
class Solution {
public:
    // 一个数为2的幂，那么它的二进制形式只能有1个1。
    // (~n + 1) ^ n 得到n最右侧的1
    bool isPowerOfTwo(int n) {
        if(n == 0 || n < 0) {
            return false;
        }
        return ((~n + 1) & n) == n;
    }
};
// @lc code=end

