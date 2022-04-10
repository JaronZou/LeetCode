/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 */

// @lc code=start
class Solution {
public:
    // 首先写出通用代码，然后打表
    // bool canWinNim(int n) {
    //     return firstHand(n);
    // }

    // bool firstHand(int n) {
    //     if(n > 0 && n <= 3) {
    //         return true;
    //     }
    //     else {
    //         // 接下来的人先手，如果接下来的人只要有一种可能输了，那么就输了
    //         return !(firstHand(n - 1) &&
    //                  firstHand(n - 2) &&
    //                  firstHand(n - 3));
    //     }
    // }

    // 打表
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
// @lc code=end

