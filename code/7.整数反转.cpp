/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    // int reverse(int x) {
    //     if(x == 0) {
    //         return 0;
    //     }
    //     // 将该数后面的0全部删除
    //     while(x % 10 == 0) {
    //         x /= 10;
    //     }
    //     // 将该数中的各个数字按个十百千位的顺序入栈
    //     bool isNegative = x < 0 ? true : false;
    //     x = std::abs(x);
    //     queue<int> iQueue;
    //     while(x != 0) {
    //         iQueue.push(x % 10);
    //         x /= 10;
    //     }
    //     // 将栈中的数依次倒出并组织成原来数的逆序数
    //     unsigned int result = 0;
    //     // 最高位数大于等于3的10位数一定发生了溢出
    //     if(iQueue.front() > 2 && iQueue.size() == 10) {
    //         return 0;
    //     }
    //     while(!iQueue.empty()) {
    //         result *= 10;
    //         result += iQueue.front();
    //         /* 运算出现了溢出 */
    //         if(result > INT_MAX) {
    //             return 0;
    //         }
    //         iQueue.pop();
    //     }
    //     return isNegative ? -static_cast<int>(result) : static_cast<int>(result);
    // }

    // int reverse(int x) {
    //     unsigned int result = 0;
    //     int len = 0;
    //     bool isNegative = x < 0 ? true : false;
    //     x = std::abs(x);
    //     bool flag = x % 10 > 2 ? true : false;
    //     while(x) {
    //         ++len;
    //         if(len == 10 && flag) {
    //             return 0;
    //         }
    //         result = result * 10 + x % 10;
    //         x /= 10;
    //     }
    //     if(result > INT_MAX) {
    //         return 0;
    //     }
    //     return isNegative ? -static_cast<int>(result) : static_cast<int>(result);
    // }


    // int reverse(int x) {
    //     int answer = 0;
    //     while(x != 0) {
    //         // 这一行亮眼
    //         if(answer < -214748364 || answer > 214748364) {
    //             return 0;
    //         }
    //         answer = answer * 10 + x % 10;
    //         x /= 10;
    //     }
    //     return answer;
    // }
};
// @lc code=end