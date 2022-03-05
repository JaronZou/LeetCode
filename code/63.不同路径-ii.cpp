/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        // 两个特殊的case
        if(obstacleGrid[0][0] == 1) {
            return 0;
        }
        if(m == 1 && n == 1) {
            return 1;
        }
        // dp含义和上一题一样，只不过这里的代码需要加上一个判断，遇到1就直接将dp[i][j]置为0
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 1; i < m; ++i) {
            if(obstacleGrid[i][0] == 1) {
                break;
            }
            dp[i][0] = 1;
        }
        for(int i = 1; i < n; ++i) {
            if(obstacleGrid[0][i] == 1) {
                break;
            }
            dp[0][i] = 1;
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(obstacleGrid[i][j] != 1) {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

