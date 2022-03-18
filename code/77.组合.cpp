/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    // 当前来到第i个数，已经选出的组合为nums，
    // void process(vector<int> &nums, int i, int n, int k) {
    //     // 还能选的数少于还要选的数
    //     if(n - i + 1 < k - nums.size()) {
    //         return;
    //     }
    //     // base case
    //     if(nums.size() == k) {
    //         result.push_back(nums);
    //         return;
    //     }
    //     if(i == n + 1) {
    //         return;
    //     }
    //     // 两种情况，选当前的数，不选当前的数
    //     // 选当前的数
    //     nums.push_back(i);
    //     process(nums, i + 1, n, k);
    //     nums.pop_back();
    //     // 不选当前数字
    //     process(nums, i + 1, n, k);
    // }

    // vector<vector<int>> combine(int n, int k) {
    //     if(k > n) {
    //         return {};
    //     }
    //     vector<int> nums;
    //     process(nums, 1, n, k);
    //     return result;
    // }

    void process(vector<int> &nums, int i, int n, int k) {
        if(nums.size() == k) {
            result.push_back(nums);
            return;
        }
        if(i == n + 1) {
            return;
        }
        while(i <= n) {
            nums.push_back(i);
            process(nums, ++i, n, k);
            nums.pop_back();
        }
    }

    // backtrace
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        process(nums, 1, n, k);
        return result;
    }

private:
    vector<vector<int>> result;
};
// @lc code=end

