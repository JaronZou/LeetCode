/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while(i < nums.size() && j < nums.size()) {
            if(nums[j] != 0) {
                std::swap(nums[i], nums[j]);
                ++i;
            }
            ++j;
        }
    }
};
// @lc code=end

