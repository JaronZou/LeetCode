/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() == 1) {
            return;
        }
        int less =  -1, more = nums.size(), equal = 0;
        while(equal != more) {
            if(nums[equal] < 1) {
                std::swap(nums[++less], nums[equal]);
                ++equal;
            }
            else if(nums[equal] > 1) {
                std::swap(nums[--more], nums[equal]);
            }
            else {
                ++equal;
            }
        }
    }
};
// @lc code=end

