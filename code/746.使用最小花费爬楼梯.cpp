/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    // 超时了
    // int minCostClimbingStairs(vector<int>& cost) {
    //     return min(process(cost, 0, 0),
    //                process(cost, 1, 0));
    // }

    // // 当前来到i位置，已经花了c块钱，继续向上爬总共需要多少钱
    // int process(const vector<int>& cost, int i, int c) {
    //     if(i >= cost.size()) {
    //         return c;
    //     }
    //     return min(process(cost, i + 1, c + cost[i]), 
    //                process(cost, i + 2, c + cost[i]));
    // }

    // 仍然超时了
    // struct Cordinate {
    //     int x, y;
    //     Cordinate() : x(0), y(0) {

    //     }
    //     Cordinate(int i, int j) : x(i), y(j) {

    //     }
    // };

    // struct CordinateEqual {
    //     bool operator()(const Cordinate &c1, const Cordinate &c2) const {
    //         return c1.x == c2.x && c1.y == c2.y;
    //     }
    // };

    // struct CordinateHash {
    //     int operator()(const Cordinate &c) const {
    //         return (c.x + 5) * 7 + c.y;
    //     }
    // };

    // int minCostClimbingStairs(vector<int>& cost) {
    //     unordered_map<Cordinate, int, CordinateHash, CordinateEqual> dp;
    //     return min(process(cost, dp, 0, 0),
    //                process(cost, dp, 1, 0));
    // }

    // int process(const vector<int>& cost, 
    //             unordered_map<Cordinate, int, CordinateHash, CordinateEqual> &dp, 
    //             int i, int c) {
    //     if(i >= cost.size()) {
    //         return c;
    //     }
    //     auto iter = dp.find({i, c});
    //     if(iter != dp.end()) {
    //         return (*iter).second;
    //     }
    //     int c1 = process(cost, dp, i + 1, c + cost[i]);
    //     int c2 = process(cost, dp, i + 2, c + cost[i]);
    //     dp[{i, c}] = min(c1, c2);
    //     return dp[{i, c}];
    // }

    int minCostClimbingStairs(vector<int>& cost) {

    }
};
// @lc code=end

