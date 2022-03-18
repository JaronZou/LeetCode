/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
    // O(m + n)空间复杂度算法
    // void setZeroes(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     vector<int> rows(m, 0);
    //     vector<int> cols(n, 0);
    //     for(int i = 0; i < m; ++i) {
    //         for(int j = 0; j < n; ++j) {
    //             if(matrix[i][j] == 0) {
    //                 rows[i] = 1;
    //                 cols[j] = 1;
    //             }
    //         }
    //     }
    //     for(int i = 0; i < m; ++i) {
    //         for(int j = 0; j < n; ++j) {
    //             if(rows[i] == 1 || cols[j] == 1) {
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }

    // O(1)算法
    void setZeroes(vector<vector<int>>& matrix) {
        // 1个变量用于判断第一列是否有0
        // 将每行是否有0的信息存储在第一列中，将1~n-1列是否有0的信息存储到第一行的1~n-1中
        int m = matrix.size();
        int n = matrix[0].size();
        bool isFirstCol0 = false;
        // 遍历第一列，如果找到0，那么isFirstCol0置为true
        for(int i = 0; i < m; ++i) {
            if(matrix[i][0] == 0) {
                isFirstCol0 = true;
                break;
            }
        }
        // 遍历整个矩阵，如果发现了0，那么将相应的存储信息的位置0
        for(int i = 0; i < m; ++i) {
            // 由于第一列已经遍历过了，这里从第二列开始遍历
            for(int j = 1; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // 按照信息在矩阵中填0，由于第一行和第一列中存储了信息，因此最后填写
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // 第一行是否有0，如果有的话，第一行置0
        if(matrix[0][0] == 0) {
            for(int i = 0; i < n; ++i) {
                matrix[0][i] = 0;
            }
        }
        // 第一列是否有0，如果有的话，第一列置0
        if(isFirstCol0) {
            for(int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
// @lc code=end

