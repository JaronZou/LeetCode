/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0, k = 0;
        while(k < nums.size()) {
            if(nums[k] == nums[i]) {
                if(j - i < 2) {
                    nums[j] = nums[k];
                    ++j;
                }
            }
            else {
                nums[j] = nums[k];
                i = j;
                ++j;
            }
            ++k;
        }
        return j;
    }
};
// @lc code=end

