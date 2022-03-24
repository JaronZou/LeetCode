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
        vector<vector<int>> ans;
        // 双指针
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            // 去重
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = n - 1;
            int target = -nums[i];
            while(j < k) {
                // 下面的两个if都是为了去重
                if(j > i + 1 && nums[j] == nums[j - 1]) {
                    ++j;
                    continue;
                }
                if(k < n - 1 && nums[k] == nums[k + 1]) {
                    --k;
                    continue;
                }
                // 找到结果
                int sum  = nums[j] + nums[k];
                if(sum == target) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                }
                else if(sum > target) {
                    --k;
                }
                else {
                    ++j;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

