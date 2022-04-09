/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() ==  0) {
            return {};
        }
        vector<string> ans;
        int i = 0, j = 1;
        while(i < nums.size()) {
            while(j < nums.size() && nums[j] == nums[j - 1] + 1) {
                ++j;
            }
            ans.push_back(to_string(nums[i]));
            if(j - 1 != i) {
                ans.back().append("->");
                ans.back().append(to_string(nums[j - 1]));
            }
            i = j;
            j = i + 1;
        }
        return ans;
    }
};
// @lc code=end

