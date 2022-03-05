/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // /* 第一个int存储第二个int所表示的位置的元素的值 */
        // multimap<int, int> valIdxMap;
        // for(int i = 0; i < nums.size(); ++i) {
        //     valIdxMap.emplace(nums[i], i);
        // }
        // for(int i = 0; i < nums.size(); ++i) {
        //     auto idxRange = valIdxMap.equal_range(target - nums[i]);
        //     if(idxRange.first == valIdxMap.end()) {
        //         continue;
        //     }
        //     while(idxRange.first != idxRange.second) {
        //         if((*idxRange.first).second != i) {
        //             return {i, (*idxRange.first).second};
        //         }
        //         ++idxRange.first;
        //     }
        // }
        // return {-1, -1};
        // 上面的方法使用了multimap(key可以重复的hashtable)，下面有更好的解法 */
        map<int, int> valIdxMap;
        /* 每次向哈希表中插入元素时检查是否存在key为valIdxMap[target - nums[i]]的元素 */
        for(int i = 0; i < nums.size(); ++i) {
            auto it = valIdxMap.find(target - nums[i]);
            if(it != valIdxMap.end()) {
                return {i, (*it).second};
            }
            valIdxMap[nums[i]] = i;
        }
        return {-1, -1};
    }
};
// @lc code=end

