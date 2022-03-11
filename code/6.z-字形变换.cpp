/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {
            return s;
        }
        vector<string> res(numRows);
        bool flag = true;
        int j = 0, k = numRows - 1;
        for(int i = 0; i < s.size(); ++i) {
            if(flag) {
                res[j].push_back(s[i]);
                ++j;
                if(j == numRows) {
                    k = numRows - 2;
                    flag = false;
                }
            }
            else {
                res[k].push_back(s[i]);
                --k;
                if(k == -1) {
                    j = 1;
                    flag = true;
                }
            }
        }
        for(int i = 1; i < res.size(); ++i) {
            res[0].append(res[i]);
        }
        return res[0];
    }
};
// @lc code=end

