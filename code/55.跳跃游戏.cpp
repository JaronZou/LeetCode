/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    // greedy
    // 每次都选择可以让我跳的最远的数字
    bool canJump(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()) {
            int curNum = nums[i];
            // 当前数字能够跳到最后一个位置
            if(curNum + i >= nums.size() - 1) {
                return true;
            }
            // 来到了元素为0的位置
            if(curNum == 0) {
                return false;
            }
            // 在可以跳到的范围内寻找可以让我跳的最远的数字
            int maxDistance = curNum;
            int nextIdx = i + curNum;
            for(int j = 1; j <= curNum; ++j) {
                int distance = j + nums[i + j];
                if(distance > maxDistance) {
                    maxDistance = distance;
                    nextIdx = i + j;
                }
            }
            // jump!
            i = nextIdx;
        }
        return false;
    }
};
// @lc code=end

