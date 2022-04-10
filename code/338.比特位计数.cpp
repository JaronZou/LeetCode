/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    // 使用循环
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; ++i) {
            int bits = 0, j = i;
            while(j != 0) {
                bits += (j & 1);
                j = j >> 1;
            }
            ans.push_back(bits);
        }
        return ans;
    }
};
// @lc code=end

