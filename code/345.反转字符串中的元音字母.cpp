/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            while(!isVowel(s[i]) && i < j) {
                ++i;
            }
            while(!isVowel(s[j]) && i < j) {
                --j;
            }
            if(i < j) {
                std::swap(s[i], s[j]);
                ++i;
                --j;
            }
        }
        return s;
    }

    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
};
// @lc code=end

