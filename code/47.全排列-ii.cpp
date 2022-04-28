/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
    }

    void dfs(vector<int> &nums, int idx) {
        if(idx == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size(); ++i) {
            if(vis.count(nums[idx]) == 0) {
                int num = nums[idx];
                vis.insert(nums[idx]);
                std::swap(nums[idx], nums[i]);
                dfs(nums, idx + 1);
                vis.erase(nums[idx]);
                std::swap(nums[idx], nums[i]);
            }
        }
    }

private:
    vector<vector<int>> ans;
    set<int> vis;
};
// @lc code=end

