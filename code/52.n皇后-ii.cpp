/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    bool isValid(vector<int> &record, int i, int j) {
        for(int k = 0; k < i; ++k) {
            if(record[k] == j || (abs(i - k) == abs(j - record[k]))) {
                return false;
            }
        }
        return true;
    }

    int process(vector<int> &record, int i) {
        if(i == record.size()) {
            return 1;
        }
        int result = 0;
        for(int j = 0; j < record.size(); ++j) {
            if(isValid(record, i, j)) {
                record[i] = j;
                result += process(record, i + 1);
            }
        }
        return result;
    }

    int totalNQueens(int n) {
        vector<int> record(n, -1);
        return process(record, 0);
    }
};
// @lc code=end

