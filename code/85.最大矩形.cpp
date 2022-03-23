/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // 记录每个位置的元素左侧(包括自生)连续的1的个数
        vector<vector<int>> leftCon1(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1') {
                    ++leftCon1[i][j];
                    if(j - 1 >= 0) {
                        leftCon1[i][j] += leftCon1[i][j - 1];
                    } 
                }
            }
        }
        // 枚举每个点作为右下角的情况，通过辅助数组计算每个位置的最大矩形面积
        int maxArea = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int curMaxArea = 0;
                int curLen = leftCon1[i][j];
                // 从当前点向上寻找，找到最大的面积
                for(int k = i; k >= 0; --k) {
                    if(leftCon1[k][j] == 0) {
                        break;
                    }
                    // 当前矩形的边长
                    if(leftCon1[k][j] < curLen) {
                        curLen = leftCon1[k][j];
                    }
                    if(curLen * (i - k + 1) > curMaxArea) {
                        curMaxArea = curLen * (i - k + 1);
                    }
                }
                if(maxArea < curMaxArea) {
                    maxArea = curMaxArea;
                }
            }
        }
        return maxArea;
    }
};
// @lc code=end

