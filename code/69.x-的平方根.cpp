/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) {
            return 1;
        }
        // INT_MAX的平方
        int left = 1, right = 46340;
        int mid;
        while(left <= right) {
            mid = (left + right) >> 1;
            if(mid * mid > x) {
                right = mid - 1;
            }
            else if(mid * mid < x) {
                left = mid + 1;
            }
            else {
                return mid;
            }
        }
        return mid * mid > x ? mid - 1 : mid;
    }
};
// @lc code=end

