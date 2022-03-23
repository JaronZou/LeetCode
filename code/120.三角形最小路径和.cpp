/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     // dp[i][j]含义为当前来到(i,j)位置，
    //     // 自底向上到达当前位置的最小路径和为dp[i][j]
    //     // dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j]
    //     int n = triangle.size();
    //     vector<vector<int>> dp(n, vector<int>(n, 0));
    //     // 初始化
    //     for(int i = 0; i < n; ++i) {
    //         dp[n - 1][i] = triangle[n - 1][i];
    //     }
    //     for(int i = n - 2; i >= 0; --i) {
    //         for(int j = i; j >= 0; --j) {
    //             dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
    //         }
    //     }
    //     return dp[0][0];
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        // 初始化
        for(int i = 0; i < n; ++i) {
            dp[i] = triangle[n - 1][i];
        }
        for(int i = n - 2; i >= 0; --i) {
            int preNum = dp[i + 1];
            for(int j = i; j >= 0; --j) {
                int temp = dp[j];
                dp[j] = triangle[i][j] + min(dp[j], preNum);
                preNum = temp;
            }
        }
        return dp[0];
    }
};
// @lc code=end

