/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 双指针，从右往左填
        int i = m - 1, j = n - 1; 
        for(int k = nums1.size() - 1; k >= 0; --k) {
            // 谁大，填谁
            if(i >= 0 && j >= 0){
                if(nums1[i] <= nums2[j]) {
                    nums1[k] = nums2[j--];
                }
                else {
                    nums1[k] = nums1[i--];
                }
            }
            else if(j >= 0) {
                nums1[k] = nums2[j--];
            }
        }
    }
};
// @lc code=end

