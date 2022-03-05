/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) {
            return nums.size();
        }
        int i = 0, j = 1;
        while(j < nums.size()) {
            if(nums[i] == nums[j]) {
                while(j < nums.size() && nums[i] == nums[j]) {
                    ++j;
                }
                if(j != nums.size()) {
                    nums[++i] = nums[j];
                }
            }
            else {
                ++i;
                ++j;
            }
        }
        return i + 1;
    }
};
// @lc code=end

