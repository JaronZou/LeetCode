/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    // struct pos {
    //     int x, y;
    //     pos(int i, int j) : x(i), y(j) {

    //     }
    //     pos() : x(0), y(0) {

    //     }
    // };

    // struct PosHash {
    //     int operator()(const pos &p) const {
    //         return (p.x + 7) * p.y + 11;
    //     }
    // };

    // struct PosEqual {
    //     bool operator()(const pos &p1, const pos &p2) const {
    //         return p1.x == p2.x && p1.y == p2.y;
    //     }
    // };

    // bool isValidSudoku(vector<vector<char>>& board) {
    //     // 遍历找到所有数字的坐标并保存到哈希表中。
    //     unordered_multimap<int, pos> cordinates;
    //     for(int i = 0; i < board.size(); ++i) {
    //         for(int j = 0; j < board[0].size(); ++j) {
    //             int num = board[i][j] - '0';
    //             if(num > 0 && num <= 9) {
    //                 cordinates.emplace(num, pos(i, j));
    //             }
    //         }
    //     }
    //     // 判断是否所有相等的数都不共行、不共列、不在同一个九宫格内
    //     for(int i = 1; i < 10; ++i) {
    //         auto iters = cordinates.equal_range(i);
    //         auto beg = iters.first;
    //         auto end = iters.second;
    //         // 列数组和行数组，用来判断数字是否在同列或同行
    //         int row[9] = {0};
    //         int col[9] = {0};
    //         // 一个集合，用来判断数字是否在同一个九宫格
    //         unordered_set<pos, PosHash, PosEqual> pSet;
    //         while(beg != end) {
    //             // 只要行除以3、列除以3，得到的两个数可以用来判断是否在同一九宫格
    //             pos p(beg->second.x / 3, beg->second.y / 3);
    //             if(pSet.count(p) != 0) {
    //                 return false;
    //             }
    //             pSet.insert(p);
    //             // 判断行列是否相等
    //             if(row[beg->second.x] != 0) {
    //                 return false;
    //             }
    //             if(col[beg->second.y] != 0) {
    //                 return false;
    //             }
    //             row[beg->second.x] = 1;
    //             col[beg->second.y] = 1;
    //             ++beg;
    //         }
    //     }
    //     return true;
    // }


    // 一次遍历
    bool isValidSudoku(vector<vector<char>>& board) {
        // cols 和 rows分别表示第j列每个数字出现的次数，和第i行每个数字出现的次数
        int cols[9][9] = {0}, rows[9][9] = {0};
        int subboxes[3][3][9] = {0};
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    // 第i行，当前数字num + 1，出现了几次
                    int num = board[i][j] - '1';
                    if(rows[i][num] != 0) {
                        return false;
                    }
                    ++rows[i][num];
                    // 第j列，当前数字num + 1，出现了几次
                    if(cols[j][num] != 0) {
                        return false;
                    }
                    ++cols[j][num];
                    // 第(i / 3, j / 3)个九宫格内，当前数字num + 1，出现了几次
                    if(subboxes[i / 3][j / 3][num] != 0) {
                        return false;
                    }
                    ++subboxes[i / 3][j / 3][num];
                }
            }
        }
        return true;
    }
};
// @lc code=end

