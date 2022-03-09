/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target < nums[0]) {
            return 0;
        }
        if(target > nums[nums.size() - 1]) {
            return nums.size();
        }
        int left = 0, right = nums.size() - 1, middle;
        middle = (left + right) / 2;
        // 二分查找
        while(left < right) {
            if(nums[middle] < target) {
                left = middle + 1;
            }
            else if(nums[middle] > target) {
                right = middle;
            }
            else {
                return middle;
            }
            middle = (right + left) / 2;
        }
        return middle;
    }
};
// @lc code=end

