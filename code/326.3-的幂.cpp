/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂
 */

// @lc code=start
class Solution {
public:
    // 使用循环的版本
    // bool isPowerOfThree(int n) {
    //     if(n <= 0) {
    //         return false;
    //     }
    //     while(n % 3 == 0) {
    //         n /= 3;
    //     }
    //     return n == 1;
    // }

    // 找到32位整数范围内所能表示的最大的 3的幂
    // 3^19 = 1162261467
    bool isPowerOfThree(int n) {
        if(n <= 0) {
            return false;
        }
        return (1162261467 % n) == 0;
    }
};
// @lc code=end

