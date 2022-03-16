/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> chmap = {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    vector<string> result;
    // 当前来到第i个字符，前面选择的字符组成的字符串为str
    void process(string &digits, string &str, int i) {
        // base case
        if(i == digits.size()) {
            result.push_back(str);
            return;
        }
        int index = digits[i] - '2';
        for(int k = 0; k < chmap[index].size(); ++k) {
            str.push_back(chmap[index][k]);
            process(digits, str, i + 1);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return {};
        }
        string str;
        process(digits, str, 0);
        return result;
    }
};
// @lc code=end

