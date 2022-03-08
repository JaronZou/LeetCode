/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    // vector<int> plusOne(vector<int>& digits) {
    //     vector<int> result(digits.size(), 0);
    //     int i = digits.size() - 1;
    //     bool carryBit = true;
    //     while(i >= 0) {
    //         if(carryBit && digits[i] != 9) {
    //             result[i] = digits[i] + 1;
    //             carryBit = false;
    //         }
    //         else if(!carryBit) {
    //             result[i] = digits[i];
    //         }
    //         --i;
    //     }
    //     if(carryBit) {
    //         result[0] = 1;
    //         result.push_back(0);
    //     }
    //     return result;
    // }

    // 找到第一个不为9的数，将该数加1，1后面的数都置为0
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        while(i >= 0) {
            if(digits[i] == 9) {
                digits[i] = 0;
            }
            else {
                digits[i] += 1;
                return digits;
            }
            --i;
        }
        // 循环结束没有返回说明所有的数都是9
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};
// @lc code=end

