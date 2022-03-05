/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = strs[0];
        for(int i = 1; i < strs.size(); ++i) {
            int n = getCommonStr(result, strs[i]);
            result = result.substr(0, n);
        }
        return result;
    }

    int getCommonStr(const string &s1, const string &s2) {
        int i;
        for(i = 0; i < s1.size() && i < s2.size(); ++i) {
            if(s1[i] != s2[i]) {
                return i;
            }
        }
        return i;
    }
};
// @lc code=end

