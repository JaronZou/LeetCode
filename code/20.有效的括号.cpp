/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                brackets.push(s[i]);
            }
            else {
                if(brackets.size() == 0) {
                    return false;
                }
                char bck = brackets.top();
                brackets.pop();
                if(s[i] == ')' && bck != '(') {
                    return false;
                }
                else if(s[i] == ']' && bck != '[') {
                    return false;
                }
                else if(s[i] == '}' && bck != '{') {
                    return false;
                }
            }
        }
        return brackets.size() == 0 ? true : false;
    }
};
// @lc code=end

