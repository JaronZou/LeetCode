/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    // 当前来到第i个数字，nums中i位置之前的数字全部已经排列完，现在需要选择谁来做第i个数
    void process(vector<int> nums, int i, vector<vector<int>> &res) {
        // 产生了一种排列
        if(i == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        // [i, nums.size() - 1]位置中的所有数都可以来到第i个位置
        for(int j = i; j < nums.size(); ++j) {
            std::swap(nums[i], nums[j]);
            process(nums, i + 1, res);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        process(nums, 0, result);
        return result;
    }
};
// @lc code=end

