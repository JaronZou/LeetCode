/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    // 使用基数排序，小于等于0的全部丢弃，大于数组大小的全部丢弃，其余的数进行基数排序
    // int firstMissingPositive(vector<int>& nums) {
    //     vector<int> help(nums.size(), 0);
    //     for(int i = 0; i < nums.size(); ++i) {
    //         if(nums[i] > 0 && nums[i] <= nums.size()) {
    //             help[nums[i] - 1] = 1; 
    //         }
    //     }
    //     for(int i = 0; i < nums.size(); ++i) {
    //         if(help[i] == 0) {
    //             return i + 1;
    //         }
    //     }
    //     return nums.size() + 1;
    // }

    // 置换：将能进行排序的元素置换到相应位置，不能进行排序的元素不懂
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            // 加while循环原因是，任何一个置换到此位置的数都可能可以再进行一次置换
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0 ; i < nums.size(); ++i) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};
// @lc code=end

