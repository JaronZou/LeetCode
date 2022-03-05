/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    // string intToRoman(int num) {
    //     string str;
    //     string s1, s2, s3;
    //     // 当前是第几位
    //     int count = 1;
    //     while(num != 0) {
    //         switch(count) {
    //         case 1:
    //             s1 = "I";
    //             s2 = "V";
    //             s3 = "X";
    //             break;
    //         case 2:
    //             s1 = "X";
    //             s2 = "L";
    //             s3 = "C";
    //             break;
    //         case 3:
    //             s1 = "C";
    //             s2 = "D";
    //             s3 = "M";
    //             break;
    //         case 4:
    //             s1 = "M";
    //             break;
    //         }
    //         int n = num % 10;
    //         num /= 10;
    //         ++count;
    //         string s;
    //         if(n < 4) {
    //             while(n > 0) {
    //                 s.append(s1);
    //                 --n;
    //             }
    //         }
    //         else if(n == 4) {
    //             s.append(s1);
    //             s.append(s2);
    //         }
    //         else if(n < 9) {
    //             s.append(s2);
    //             n -= 5;
    //             while(n > 0) {
    //                 s.append(s1);
    //                 --n;
    //             }
    //         }
    //         else {
    //             s.append(s1);
    //             s.append(s3);
    //         }
    //         str = s + str;
    //     }
    //     return str;
    // }


    // 贪心算法
    string intToRoman(int num) { 
        string str;
        vector<int> values={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> rom={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        for(int i = 0; i < values.size() && num != 0; ++i) {
            while(num >= values[i]) {
                str.append(rom[i]);
                num -= values[i];
            }
        }
        return str;
    }
};
// @lc code=end

