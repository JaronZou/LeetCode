/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    // 原地基数排序，排序后从0开始缺少的第一个数就是答案
    int missingNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            int j = i;
            while(nums[j] < nums.size() && j != nums[j]) {
                std::swap(nums[j], nums[nums[j]]);
                j = i;
            }
        }
        int i = 0;
        while(i < nums.size() && nums[i] == i){
            ++i;
        }
        return i;
    }
};
// @lc code=end

