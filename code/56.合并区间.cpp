/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1 || intervals.size() == 0) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        vector<int> pre = result.back(), cur(2, 0);
        for(int i = 1; i < intervals.size(); ++i) {
            cur = intervals[i];
            // 两个区间不能合并
            if(pre[1] < cur[0]) {
                result.push_back(cur);
                pre = result.back();
            }
            // 两个区间可以合并
            else if(cur[1] > pre[1]) {
                result.back()[1] = cur[1];
                pre = result.back();
            }
        }
        return result;
    }
};
// @lc code=end

