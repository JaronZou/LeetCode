/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    // bool isValid(vector<int> &record, int i, int j) {
    //     for(int k = 0; k < i; ++k) {
    //         if(record[k] == j || (abs(i - k) == abs(j - record[k]))) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // int process(vector<int> &record, int i) {
    //     if(i == record.size()) {
    //         return 1;
    //     }
    //     int result = 0;
    //     for(int j = 0; j < record.size(); ++j) {
    //         if(isValid(record, i, j)) {
    //             record[i] = j;
    //             result += process(record, i + 1);
    //         }
    //     }
    //     return result;
    // }

    // int totalNQueens(int n) {
    //     vector<int> record(n, -1);
    //     return process(record, 0);
    // }

    // limit用位的方法表示有多少个皇后，limit的右侧有多少个1，就表示有多少个皇后
    // colLim前面的皇后的列限制
    // leftDiaLim表示前面的皇后的左斜线限制
    // rightDiaLim表示前面的皇后的右斜线限制
    int process(int limit, int colLim, int leftDiaLim, int rightDiaLim) {
        if(limit == colLim) {
            return 1;
        }
        int pos = 0;
        int mostRight = 0;
        // pos中的位1表示可以填皇后，0表示不能填皇后
        pos = limit & (~(colLim | leftDiaLim | rightDiaLim));
        int res = 0;
        while(pos != 0) {
            // pos & (~pos + 1)获得最右侧的1
            mostRight = pos & (~pos + 1);
            pos -= mostRight;
            res += process(limit, (colLim | mostRight),
                        ((leftDiaLim | mostRight) << 1),
                        ((rightDiaLim | mostRight) >> 1));
        }
        return res;
    }

    int totalNQueens(int n) {
        int limit = 0;
        limit = (1 << n) - 1;
        return process(limit, 0, 0, 0);
    }
};
// @lc code=end

