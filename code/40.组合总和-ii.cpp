/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        backtrace(candidates, path, 0, target);
        return result;
    }

    void backtrace(vector<int> candidates, vector<int> &path, int index, int remains) {
        if(remains == 0) {
            result.push_back(path);
            return;
        }
        for(int i = index; i < candidates.size(); ++i) {
            if(candidates[i] > remains) {
                return;
            }
            if(i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            path.push_back(candidates[i]);
            backtrace(candidates, path, i + 1, remains - candidates[i]);
            path.pop_back();
        }
    }

private:
    vector<vector<int>> result;
};
// @lc code=end

 