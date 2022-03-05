/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    // int fib(int n) {
    //     if(n == 0 || n == 1) {
    //         return n;
    //     }   
    //     return fib(n - 1) + fib(n - 2);
    // }

    int fib(int n) {
        if(n == 0 || n == 1) {
            return n;
        }
        int pre1 = 0, pre2 = 1, cur;
        for(int i = 2; i <= n; ++i) {
            cur = pre1 + pre2;
            pre1 = pre2;
            pre2 = cur;
        }
        return cur;
    }
};
// @lc code=end

