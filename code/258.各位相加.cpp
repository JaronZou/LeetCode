/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    // vector<int> getAllBit(int num) {
    //     vector<int> bits;
    //     while(num != 0) {
    //         if(num % 10 != 0) {
    //             bits.push_back(num % 10);
    //         }
    //         num /= 10;
    //     }
    //     return bits;
    // }

    // int addDigits(int num) {
    //     vector<int> bits;
    //     while(num >= 10) {
    //         bits = std::move(getAllBit(num));
    //         num = 0;
    //         for(int i = 0; i < bits.size(); ++i) {
    //             num += bits[i];
    //         }
    //     }
    //     return num;
    // }

    // int addDigits(int num) {
    //     if(num < 10) {
    //         return num;
    //     }
    //     int newNum = 0;
    //     while(num != 0) {
    //         newNum += num % 10;
    //         num /= 10;
    //     }
    //     return addDigits(newNum);
    // }

    // 例如某数xyzk,可以分解为xyzk = 1000*x + 100*y + 10*z + k = 999*x + 99*y + 9 *z + (x + y + z + k)，
    // 括号内即为所求(或下一次迭代)。
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};
// @lc code=end

