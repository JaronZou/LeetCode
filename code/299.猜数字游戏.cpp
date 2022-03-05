/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
public:
    // string getHint(string secret, string guess) {
    //     priority_queue<char> bigQue1, bigQue2;
    //     int bulls = 0, cows = 0;
    //     for(int i = 0; i < secret.size(); ++i) {
    //         if(secret[i] == guess[i]) {
    //             ++bulls;
    //         }
    //         else {
    //             bigQue1.push(secret[i]);
    //             bigQue2.push(guess[i]);
    //         }
    //     }
    //     while(!bigQue1.empty() && !bigQue2.empty()) {
    //         if(bigQue1.top() > bigQue2.top()) {
    //             bigQue1.pop();
    //         }
    //         else if(bigQue2.top() > bigQue1.top()) {
    //             bigQue2.pop();
    //         }
    //         else {
    //             ++cows;
    //             bigQue1.pop();
    //             bigQue2.pop();
    //         }
    //     }
    //     return to_string(bulls) + "A" + to_string(cows) + "B";
    // }

    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        int cowsNum1[10] = {0}, cowsNum2[10] = {0};
        for(int i = 0; i < secret.size(); ++i) {
            if(secret[i] == guess[i]) {
                ++bulls;
            }
            else {
                ++cowsNum1[secret[i] - '0'];
                ++cowsNum2[guess[i] - '0'];
            }
        }
        for(int i = 0; i < 10; ++i) {
            if(cowsNum1[i] != 0 && cowsNum2[i] != 0) {
                cows += min(cowsNum1[i], cowsNum2[i]);
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
// @lc code=end

