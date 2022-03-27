/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    // 当前的括号序列，当前来到idx位置，剩余leftRemain个左括号可用，rightRemain个右括号可用
    void backtrace(string &curBrac, int idx, int leftRemain, int rightRemain, int n) {
        if(leftRemain == 0 && rightRemain == 0) {
            brackets.push_back(curBrac);
            return;
        }
        if(leftRemain > 0) {
            curBrac[idx] = '(';
            backtrace(curBrac, idx + 1, leftRemain - 1, rightRemain, n);
        }
        if(rightRemain > leftRemain) {
            curBrac[idx] = ')';
            backtrace(curBrac, idx + 1, leftRemain, rightRemain - 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        string curBrac(n * 2, '(');
        backtrace(curBrac, 0, n, n, n);
        return brackets;
    }
private:
    vector<string> brackets;
};
// @lc code=end

