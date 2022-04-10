/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */

// @lc code=start
class Solution {
public:
    // 二进制上只有一个1，并且都在奇数位上
    bool isPowerOfFour(int n) {
        if(n <= 0) {
            return false;
        }
        // 1431655765 ==> 0101,0101,0101,0101,0101,0101,0101,0101 
        return (((~n + 1) & n) == n) && (n & 1431655765);
    }
};
// @lc code=end

