/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    // 由于每个数字各不相同，回溯
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> help;
        dfs(nums, help, 0);
        return ans;
    }

    void dfs(vector<int>& nums, vector<int> &help, int n) {
        if(n == nums.size()) {
            ans.push_back(help);
            return;
        }
        dfs(nums, help, n + 1);
        help.push_back(nums[n]);
        dfs(nums, help, n + 1);
        help.pop_back();
    }

private:
    vector<vector<int>> ans;
};
// @lc code=end

