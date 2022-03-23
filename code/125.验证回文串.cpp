/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    // 双指针
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(!isalnum(s[i])) {
                ++i;
                continue;
            }
            if(!isalnum(s[j])) {
                --j;
                continue;
            }
            if(tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};
// @lc code=end

