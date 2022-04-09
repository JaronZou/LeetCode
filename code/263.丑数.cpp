/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
    // n 除以所有 3 个质因数，直至 n 不能整除所有 3 个质因数
    // 如果 n 为 1，那么返回 true，否则返回 false。
    bool isUgly(int n) {
        if(n == 0 || n < 0) {
            return false;
        }
        int nums[3] = {2, 3, 5};
        for(int i = 0; i < 3; ++i) {
            while(n % nums[i] == 0) {
                n /= nums[i];
            }
        }
        return n == 1;
    }
};
// @lc code=end

