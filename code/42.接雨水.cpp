/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    // 暴力解法
    // 超时了
    // int trap(vector<int>& height) {
    //     int ans = 0;
    //     for(int i = 0; i < height.size(); ++i) {
    //         int leftMax = i, rightMax = i;
    //         for(int j = i - 1; j >= 0; --j) {
    //             if(height[j] > height[leftMax]) {
    //                 leftMax = j;
    //             }
    //         }
    //         for(int j = i + 1; j < height.size(); ++j) {
    //             if(height[j] > height[rightMax]) {
    //                 rightMax = j;
    //             }
    //         }
    //         if(leftMax != i && rightMax != i) {
    //             ans += min(height[leftMax], height[rightMax]) - height[i];
    //         }
    //     }
    //     return ans;
    // }

    // 动态规划
    // int trap(vector<int>& height) {
    //     // 由上面的暴力解法推出，我们只需要创建两个数组保存每个位
    //     // 置最右侧最高元素和最左侧最高元素即可
    //     int n = height.size();
    //     vector<int> leftMax(n, 0);
    //     vector<int> rightMax(n, 0);
    //     for(int i = 0; i < n; ++i) {
    //         leftMax[i] = height[i];
    //         if(i - 1 >= 0 && leftMax[i] < leftMax[i - 1]) {
    //             leftMax[i] = leftMax[i - 1];
    //         }
    //     }
    //     for(int i = n - 1; i >= 0; --i) {
    //         rightMax[i] = height[i];
    //         if(i + 1 < n && rightMax[i] < rightMax[i + 1]) {
    //             rightMax[i] = rightMax[i + 1];
    //         }
    //     }
    //     int ans = 0;
    //     for(int i = 1; i < n - 1; ++i) {
    //         ans += min(leftMax[i], rightMax[i]) - height[i];
    //     }
    //     return ans;
    // }

    // 单调栈
    // int trap(vector<int>& height) {
    //     stack<int> stk;
    //     int ans = 0;
    //     for(int i = 0; i < height.size(); ++i) {
    //         while(!stk.empty() && height[stk.top()] < height[i]) {
    //             int h = height[stk.top()];
    //             stk.pop();
    //             if(!stk.empty()) {
    //                 int leftIdx = stk.top();
    //                 int currWidth = i - leftIdx - 1;
    //                 int currHeight = min(height[leftIdx], height[i]) - h;
    //                 ans += currWidth * currHeight;
    //             }
    //         }
    //         stk.push(i);
    //     }
    //     return ans;
    // }

    // 双指针
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = height[left], rightMax = height[right], ans = 0;
        while(left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if(height[left] < height[right]) {
                ans += leftMax - height[left];
                ++left;
            }
            else {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};
// @lc code=end

