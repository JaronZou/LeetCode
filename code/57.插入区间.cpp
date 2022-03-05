/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) { 
        if(intervals.size() == 0) {
            return {newInterval};
        }
        vector<vector<int>> result;
        vector<int> preInterval, curInterval;
        // 谁小取谁
        bool isInsert = newInterval <= intervals[0];
        preInterval = isInsert ? newInterval : intervals[0];
        int i = isInsert ? 0 : 1;
        while(i < intervals.size()) {
            // newInterval还没有插入
            if(!isInsert && (newInterval <= intervals[i])) {
                curInterval = newInterval;
                isInsert = true;
            }
            else {
                curInterval = intervals[i++];
            }
            // 合并preInterval和curInterval，如果不能合并，那么将其放到result中
            if(curInterval[0] <= preInterval[1]) {
                preInterval[1] = max(preInterval[1], curInterval[1]);
            }
            else {
                result.push_back(preInterval);
                preInterval = curInterval;
            }
        }
        // 最后都没插入
        if(!isInsert) {
            // 可以合并
            if(newInterval[0] <= preInterval[1]) {
                preInterval[1] = max(newInterval[1], preInterval[1]);
            }
            else {
                result.push_back(preInterval);
                preInterval = newInterval;
            }
        }
        result.push_back(preInterval);
        return result;
    }
};
// @lc code=end

