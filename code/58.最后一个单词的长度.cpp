/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int begin, end;
        // 下一个字符是不是新单词
        bool next = true;
        for(int i = 0; i < s.size(); ++i) {
            if(isalpha(s[i])) {
                if(next) {
                    begin = i;
                    end = i;
                    next = false;
                }
                ++end;
                
            }
            else {
                next = true;
            }
        }
        return end - begin;
    }
};
// @lc code=end

