/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    // bool isPalindrome(int x) {
    //     if(x < 0) {
    //         return false;
    //     }
    //     if(x < 10) {
    //         return true;
    //     }
    //     stack<char> iStack;
    //     int tmp = x;
    //     while(tmp) {
    //         iStack.push(tmp % 10);
    //         tmp /= 10;
    //     }
    //     while(x) {
    //         if(x % 10 != iStack.top()) {
    //             return false;
    //         }
    //         iStack.pop();
    //         x /= 10;
    //     }
    //     return true;
    // }

    // bool isPalindrome(int x) {
    //     if(x < 0) {
    //         return false;
    //     }
    //     int temp = x;
    //     long long reverseX = 0;
    //     while(temp) {
    //         reverseX = reverseX * 10 + temp % 10;
    //         temp /= 10;
    //     }
    //     return reverseX == x;
    // }

    bool isPalindrome(int x) {
        // 注意：一定要先把末尾含有0的非零数排除
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int res = 0;
        /* 当res >= x时，说明已经反转了一半的字符串 */
        while(res < x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res == x || res / 10 == x;
    }
};
// @lc code=end

