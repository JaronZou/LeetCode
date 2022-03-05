/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    /* 递归实现，一共987个case，过了986个，剩下最后一个含有两万个字符的字符串没过，可能是堆栈溢出了 */
    // int lengthOfLongestSubstring(string s) {
    //     if(s == "") {
    //         return 0;
    //     }
    //     int max = INT_MIN;
    //     set<char> chSet;
    //     for(int i = 0; i < s.size(); ++i) {
    //         int len = process(s, i, chSet);
    //         max = max > len ? max : len;
    //     }
    //     return max;
    // }

    // int process(const string &str, int i, set<char> chSet) {
    //     if(chSet.find(str[i]) != chSet.end() || i >= str.size()) {
    //         return 0;
    //     }
    //     else {
    //         chSet.insert(str[i]);
    //         return 1 + process(str, i + 1, chSet);
    //     }
    // }

    /* 暴力枚举，太慢了 */
    // int lengthOfLongestSubstring(string s) {
    //     if(s == "") {
    //         return 0;
    //     }
    //     int maxlen = INT_MIN;
    //     for(int i = 0; i < s.size(); ++i) {
    //         int len = lenOfSubstr(s, i);
    //         maxlen = (len > maxlen) ? len : maxlen;
    //     }
    //     return maxlen;
    // }

    // int lenOfSubstr(const string &str, int i) {
    //     set<char> chSet;
    //     int len = 0;
    //     while((i < str.size()) && (chSet.find(str[i]) == chSet.end())) {
    //         chSet.insert(str[i++]);
    //         ++len;
    //     }
    //     return len;
    // }

    /* 滑动窗口 */
    // int lengthOfLongestSubstring(string s) {
    //     if(s == "") {
    //         return 0;
    //     }
    //     int maxlen = INT_MIN;
    //     unordered_set<int> chSet;
    //     /* 当前记录的字符串的长度 */
    //     int len = 0; 
    //     /* i, j分别为子字符串的左右指针 */
    //     for(int i = 0, j = 0; j < s.length();) {
    //         /* 当前子串还可以继续往前计数 */
    //         if(!chSet.count(s[j])) {
    //             chSet.insert(s[j++]);
    //             ++len;
    //         } 
    //         /* 某一个子串走到头了 */
    //         else {
    //             maxlen = len > maxlen ? len : maxlen;
    //             while(chSet.count(s[j])) {
    //                 chSet.erase(s[i++]);
    //                 --len;
    //             }
    //         }
    //     }
    //     maxlen = len > maxlen ? len : maxlen;
    //     return maxlen;
    // }

    /* 但其实题目给出了s由英文字母、数字、符号和空格组成，
       因此可以将其作为ASCII字符串，对于ASCII字符串，我
       们可以使用数组而不需要使用哈希表记录 */
    int lengthOfLongestSubstring(string s) {
        if(s == "") {
            return 0;
        }
        vector<int> chArr(256, 0);
        /* i、j各为左右指针 */
        int i = 0, j = 0;
        int maxlen = INT_MIN;
        while(j < s.size()) {
            if(chArr[s[j]] == 0) {
                chArr[s[j++]] = 1;
            }
            /* 找到了一个重复字符，一个字串走完，长度为j - i */
            else {
                maxlen = (j - i) > maxlen ? (j - i) : maxlen;
                /* 窗口向右滑动 */
                while(chArr[s[j]] != 0) {
                    chArr[s[i++]] = 0;
                }
            }
        }
        /* 注意：从循环出来的时候也走完了一个字串，但并没有参与maxlen的更新 */
        maxlen = (j - i) > maxlen ? (j - i) : maxlen;
        return maxlen;
    }
};
// @lc code=end

