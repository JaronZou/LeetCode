/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    // string countAndSay(int n) {
    //     if(n == 1) {
    //         return "1";
    //     }
    //     --n;
    //     string preStr = "1";
    //     string str;
    //     while(n > 0) {
    //         char curCh = preStr[0];
    //         int curChNum = 1;
    //         for(int i = 1; i < preStr.size(); ++i) {
    //             if(curCh == preStr[i]) {
    //                 ++curChNum;
    //             }
    //             // 结算前面计算到的字符
    //             else {
    //                 str.append(to_string(curChNum));
    //                 str.push_back(curCh);
    //                 // 现在开始计算新的字符
    //                 curCh = preStr[i];
    //                 curChNum = 1;
    //             }
    //         }
    //         str.append(to_string(curChNum));
    //         str.push_back(curCh);
    //         // 开始计算str的描述字符串
    //         preStr = str;
    //         str = "";
    //         --n;
    //     }
    //     return preStr;
    // }


    // 和上面的思路一样，重构了代码
    string countAndSay(int n) {
        --n;
        string preStr = "1";
        string str;
        while(n > 0) {
            int preIdx = 0, curIdx = 0;
            while(curIdx < preStr.size()) {
                while(preStr[curIdx] == preStr[preIdx] && curIdx < preStr.size()) {
                    ++curIdx;
                }
                str.append(to_string(curIdx - preIdx));
                str.push_back(preStr[preIdx]);
                preIdx = curIdx;
            }
            // 开始计算str的描述字符串
            preStr = str;
            str = "";
            --n;
        }
        return preStr;
    }
};
// @lc code=end

