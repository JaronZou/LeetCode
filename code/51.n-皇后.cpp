/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
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

    void process(vector<int> &record, int i, vector<vector<string>> &result) {
        if(i == record.size()) {
            string str(record.size(), '.');
            vector<string> strs(record.size(), str);
            for(int k = 0; k < record.size(); ++k) {
                strs[k][record[k]] = 'Q'; 
            }
            result.push_back(strs);
            return;
        }
        for(int j = 0; j < record.size(); ++j) {
            if(isValid(record, i, j)) {
                record[i] = j;
                process(record, i + 1, result);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> record(n, -1);
        vector<vector<string>> result;
        process(record, 0, result);
        return result;
    }
};
// @lc code=end

