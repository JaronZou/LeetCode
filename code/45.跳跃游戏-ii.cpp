/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    // greedy
    // 每次都选择当前可以选择的最大跳跃值
    int jump(vector<int>& nums) {
        if(nums.size() == 1) {
            return 0;
        }
        int times = 0;
        int i = 0;
        while(i < nums.size()) {
            int curNum = nums[i];
            if(curNum + i >= nums.size() - 1) {
                return times + 1;
            }
            int maxDistance = curNum;
            int nextIdx = i + curNum;
            // 选择当前可以选择的最大跳跃值
            for(int j = 0; j <= curNum; ++j) {
                if(j + nums[i + j] > maxDistance) {
                    maxDistance = j + nums[i + j];
                    nextIdx = i + j;
                }
            }
            i = nextIdx;
            ++times;
        }
        return times;
    }
};
// @lc code=end

