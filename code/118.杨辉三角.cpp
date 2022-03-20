/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        for(int i = 0; i < numRows; ++i) {
            result.emplace_back(i + 1, 1);
        }
        if(numRows == 1 || numRows == 2) {
            return result;
        }
        for(int i = 2; i < numRows; ++i) {
            for(int j = 1; j < i; ++j) {
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }
        return result;
    }
private:
    vector<vector<int>> result;
};
// @lc code=end

