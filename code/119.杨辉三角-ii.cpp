/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
    // vector<int> getRow(int rowIndex) {
    //     if(rowIndex == 0) {
    //         return {1};
    //     }
    //     if(rowIndex == 1) {
    //         return {1, 1};
    //     }
    //     vector<int> lastrow(2, 1);
    //     vector<int> currow(2, 1);
    //     for(int i = 2; i <= rowIndex; ++i) {
    //         currow.push_back(1);
    //         for(int j = 1; j < i; ++j) {
    //             currow[j] = lastrow[j - 1] + lastrow[j];
    //         }
    //         lastrow = currow;
    //     }
    //     return lastrow;
    // }

    // 原地递推
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 1);
        for(int i = 2; i <= rowIndex; ++i) {
            int j = i - 1;
            while(j >= 1) {
                // 从后往前递推，保证不会覆盖所需要的信息，妙哉妙哉
                ans[j] = ans[j] + ans[j - 1];
                --j;
            }
        }
        return ans;
    }
};
// @lc code=end

