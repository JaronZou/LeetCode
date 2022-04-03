/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //     for(int i = 0; i < nums.size(); ++i) {
    //         if(numMap.count(nums[i]) == 0) {
    //             numMap[nums[i]] = 1;
    //         }
    //         else {
    //             ++numMap[nums[i]];
    //         }
    //     }
    //     dfs(nums, numMap.cbegin());
    //     return ans;
    // }

    // void dfs(vector<int> &nums, map<int, int>::const_iterator beg) {
    //     if(beg == numMap.cend()) {
    //         ans.push_back(help);
    //         return;
    //     }
    //     auto iter = beg;
    //     ++iter;
    //     // 拿0个
    //     dfs(nums, help, iter);
    //     // 拿1个 ~ 拿k个，k表示当前数字的数量
    //     for(int i = 0; i < beg->second; ++i) {
    //         help.push_back(beg->first);
    //         dfs(nums, help, iter);
    //     }
    //     for(int i = 0; i < beg->second; ++i) {
    //         help.pop_back();
    //     }
    // }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(true, nums, 0);
        return ans;
    }

    void dfs(bool choosePre, vector<int>& nums, int i) {
        if(i == nums.size()) {
            ans.push_back(help);
            return;
        }
        // 不选当前的数
        dfs(false, nums, i + 1);
        // 如果前面的数没选，且当前的数等于前面的数，直接跳过
        if(!choosePre && i > 0 && nums[i] == nums[i - 1]) {
            return;
        }
        // 选当前的数
        help.push_back(nums[i]);
        dfs(true, nums, i + 1);
        help.pop_back();
    }   

private:
    // map<int, int> numMap;
    vector<vector<int>> ans;
    vector<int> help;
};
// @lc code=end

