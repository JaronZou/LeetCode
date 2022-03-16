/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    // // 当前来到index位置的元素，还需要拼出target大小的数字，已经使用的数字存储在nums中
    // void process(vector<int> &candidates, vector<vector<int>> &result, vector<int> &nums, int index, int target) {
    //     // base case
    //     if(target == 0) {
    //         result.push_back(nums);
    //         return;
    //     }
    //     if(target < 0 || candidates.size() == index) {
    //         return;
    //     }
    //     // 两种情况，
    //     // 1. 要当前元素
    //     // 2. 不要当前元素

    //     // 不要当前元素
    //     process(candidates, result, nums, index + 1, target);
    //     // 要当前元素
    //     nums.push_back(candidates[index]);
    //     // 下一次继续从当前元素开始挑选
    //     process(candidates, result, nums, index, target - candidates[index]);
    //     nums.pop_back();
    // }

    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //     if(candidates.size() == 0) {
    //         return {};
    //     }
    //     vector<vector<int>> result;
    //     vector<int> nums;
    //     process(candidates, result, nums, 0, target);
    //     return result;
    // }

    void backtrace(vector<vector<int>> &result, vector<int> &candidates, vector<int> &path, int index, int remains) {
        // base case
        if(remains == 0) {
            result.push_back(path);
            return;
        }
        for(int i = index; i < candidates.size(); ++i) {
            if(candidates[i] > remains) {
                return;
            }
            path.push_back(candidates[i]);
            backtrace(result, candidates, path, i, remains - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path;
        backtrace(result, candidates, path, 0, target);
        return result;
    }
};
// @lc code=end

