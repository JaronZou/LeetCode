/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // 使用哈希表存储每一个值对应的位置
        multimap<int, int> indexMap;
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); ++i) {
            indexMap.emplace(nums[i], i);
        }
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                int diff = -(nums[i] + nums[j]);
                // 查找-(nums[i] + nums[j])是否存在
                auto range = indexMap.equal_range(diff);
                for(auto iter = range.first; iter != range.second; ++iter) {
                    if(iter->second > j) {
                        ans.push_back({nums[i], nums[j], nums[iter->second]});
                    }
                }   
            }
        }
        return ans;
    }
};
// @lc code=end

