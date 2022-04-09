/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        set<int> lockedNum;
        while(n != 0) {
            lockedNum.insert(n);
            int nCopy = n;
            n = 0;
            while(nCopy) {
                int num = nCopy % 10;
                n += pow(num, 2);
                nCopy /= 10;
            }
            if(lockedNum.count(n) != 0) {
                break;
            }
        }
        return n == 1 ? true : false;
    }
};
// @lc code=end

