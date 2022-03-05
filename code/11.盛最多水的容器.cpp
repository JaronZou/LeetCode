/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    // int getVolume(vector<int>& height, int i, int j) {
    //     return min(height[i], height[j]) * (j - i);
    // }

    // int maxArea(vector<int>& height) {
    //     if(height.size() <= 1) {
    //         return 0;
    //     }
    //     int maxVolume = 0;
    //     for(int i = 0; i < height.size(); ++i) {
    //         for(int j = i + 1; j < height.size(); ++j) {
    //             int newVolume = getVolume(height, i, j);
    //             if(newVolume > maxVolume) {
    //                 maxVolume = newVolume;
    //             }
    //         }
    //     }
    //     return maxVolume;
    // }

    // int maxArea(vector<int>& height) { 
    //     return process(height, 0, height.size() - 1);
    // }


    // // 当前左边界来到i位置，右边界来到j位置，在此区域上寻找最大的容积
    // int process(vector<int>& height, int i, int j) {
    //     // base case
    //     if(i >= j) {
    //         return 0;
    //     }
    //     else if(i < 0) {
    //         return 0;
    //     }
    //     else if(j >= height.size()) {
    //         return 0;
    //     }
    //     else {
    //         int v1 = min(height[i], height[j]) * (j - i);
    //         int v2 = max(process(height, i, j - 1), 
    //                      process(height, i + 1, j));
    //         return max(v1, v2);
    //     }
    // }

    // int maxArea(vector<int>& height) { 
    //     vector<vector<int>> dp(height.size(), vector<int>(height.size(), -1));
    //     return process(height, 0, height.size() -1, dp);
    // }

    // int process(vector<int>& height, int i, int j, vector<vector<int>> &dp) {
    //     if(dp[i][j] != -1) {
    //         return dp[i][j];
    //     }
    //     // 发生越界，直接返回
    //     if(i < 0) {
    //         return 0;
    //     }
    //     else if(j >= height.size()) {
    //         return 0;
    //     }
    //     else if(i >= j) {
    //         dp[i][j] = 0;
    //     }
    //     else {
    //         int v1 = min(height[i], height[j]) * (j - i);
    //         int v2 = max(process(height, i, j - 1, dp), 
    //                      process(height, i + 1, j, dp));
    //         dp[i][j] = max(v1, v2);
    //     }
    //     return dp[i][j];
    // }

    // int maxArea(vector<int>& height) { 
    //     if(height.size() < 2) {
    //         return 0;
    //     }
    //     vector<vector<int>> dp(height.size(), vector<int>(height.size(), -1));
    //     for(int n = 0; n < height.size(); ++n) {
    //         for(int i = 0, j = i + n; j < height.size(); ++i, ++j) {
    //             if(i == j) {
    //                 dp[i][j] = 0;
    //             }
    //             else {
    //                 int volume = min(height[i], height[j]) * (j - i);
    //                 dp[i][j] = max(volume, max(dp[i][j - 1], dp[i + 1][j]));
    //             }
    //         }
    //     }
    //     return dp[0][height.size() - 1];
    // }

    // int maxArea(vector<int>& height) { 
    //     int i = 0, j = height.size() - 1;
    //     int maxVolume = 0;
    //     while(i < j) {
    //         int nowVolume = min(height[i], height[j]) * (j - i);
    //         if(maxVolume < nowVolume) {
    //             maxVolume = nowVolume;
    //         }
    //         // 因为容积的大小是由最小的边决定的，每次移动时，我们都保留较大的边
    //         // 而较小的边的哪一方移动，因此更有机会获得更大的容积。
    //         if(height[i] < height[j]) {
    //             ++i;
    //         }
    //         else {
    //             --j;
    //         }
    //     }
    //     return maxVolume;
    // }

    int maxArea(vector<int>& height) { 
        int i = 0, j = height.size() -1;
        int maxVolume = 0, nowVolume;
        while(i < j) {
            int w = j - i;
            int h = min(height[i], height[j]);
            nowVolume = w * h;
            if(maxVolume < nowVolume) {
                maxVolume = nowVolume;
            }
            // 对于较小的边，一直跳过寻找直到找出一个比当前边大的边
            while(height[i] <= h && i < j) {
                ++i;
            }
            while(height[j] <= h && i < j) {
                --j;
            }
        }
        return maxVolume;
    }
};
// @lc code=end

