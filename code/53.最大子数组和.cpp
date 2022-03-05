/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    // 二维表动态规划（超时）
    // int maxSubArray(vector<int>& nums) {
    //     if(nums.size() == 1) {
    //         return nums[0];
    //     }
    //     int maxSum = INT_MIN;
    //     // dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1](if (i + 1 >= j - 1))
    //     vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
    //     // 初始化
    //     for(int i = 0; i < nums.size(); ++i) {
    //         dp[i][i] = nums[i];
    //         if(maxSum < nums[i]) {
    //             maxSum = nums[i];
    //         }
    //     }
    //     for(int i = 1; i < nums.size(); ++i) {
    //         for(int j = 0; j < nums.size() - i; ++j) {
    //             dp[j][j + i] = dp[j][j + i - 1] + dp[j + 1][j + i];
    //             if(j + 1 <= j + i - 1) {
    //                 dp[j][j + i] -= dp[j + 1][j + i - 1];
    //             }
    //             if(maxSum < dp[j][j + i]) {
    //                 maxSum = dp[j][j + i];
    //             }
    //         }
    //     }
    //     return maxSum;
    // }

    // 贪心
    // int maxSubArray(vector<int>& nums) {
    //     int maxSum = nums[0], preSum = nums[0];
    //     for(int i = 1; i < nums.size(); ++i) {
    //         // 前面元素的和小于0，那么丢弃前面元素的和
    //         if(preSum < 0) {
    //             preSum = 0;
    //         }
    //         // 前面的元素和加上当前的元素
    //         preSum += nums[i];
    //         if(preSum > maxSum) {
    //             maxSum = preSum;
    //         }
    //     }
    //     return maxSum;
    // }

    // 一维表动态规划
    int maxSubArray(vector<int>& nums) {
        // dp[i]指的是以当前元素为结尾的最大子数组和
        // 如果dp[i - 1] <= 0(也就是说以前一个元素为结尾的子数组的最大和小于0)，那么我们就抛弃前面的数组，因为前面数组的和只会让当前的子数组和变小。
        // 可以推出dp[i] = nums[i] + (dp[i - 1] <= 0 ? 0 : dp[i - 1])
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int maxSum = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            dp[i] = nums[i] + (dp[i - 1] <= 0 ? 0 : dp[i - 1]);
            if(maxSum < dp[i]) {
                maxSum = dp[i];
            }
        }
        return maxSum;
    }
};
// @lc code=end

