/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    Solution() : rows(9, bitset<9>()), 
                 cols(9, bitset<9>()), 
                 subboxes(3, vector<bitset<9>>(3, bitset<9>())),
                 nfSpace() {
    }

    void solveSudoku(vector<vector<char>>& board) {
        // 将数独信息存储在这三个数组中。
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    rows[i][num] = true;
                    cols[j][num] = true;
                    subboxes[i / 3][j / 3][num] = true;
                }
                else {
                    nfSpace.emplace_back(i, j);
                }
            }
        }
        process(board, 0);
    }

    // 当前来到(i, j)位置填写数独
    bool process(vector<vector<char>> &board, int index) {
        // 数独中所有的数都已经填完
        if(index == nfSpace.size()) {
            return true;
        }
        int row = nfSpace[index].first;
        int col = nfSpace[index].second;
        // 当前来到(row, col)位置有多少个数可以填写
        vector<int> nexts = getNexts(row, col);
        // 当前没有数字可以填写
        if(nexts.size() == 0) {
            return false;
        }
        for(int i = 0; i < nexts.size(); ++i) {
            int num = nexts[i];
            // 填写这个数
            board[row][col] = num + '1';
            rows[row][num] = true;
            cols[col][num] = true;
            subboxes[row / 3][col / 3][num] = true;
            // 填写其他的数
            int flag = process(board, index + 1);
            // 这个填写方案对了，直接返回
            if(flag) {
                return true;
            }
            // 填写方案出错，继续填，直到找到一个正确的填写方案
            else {
                rows[row][num] = false;
                cols[col][num] = false;
                subboxes[row / 3][col / 3][num] = false;
            }
        }
        return false;
    }

    // 当前来到(i, j)位置有多少个数可以填写
    vector<int> getNexts(int i, int j) {
        vector<int> res;
        for(int k = 0; k < 9; ++k) {
            if(!rows[i][k] && !cols[j][k] && !subboxes[i / 3][j / 3][k]) {
                res.push_back(k);
            }
        }
        return res;
    }

private:
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<vector<bitset<9>>> subboxes;
    vector<pair<int, int>> nfSpace;
};
// @lc code=end

