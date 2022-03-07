/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    // int search(vector<int>& nums, int target) {
    //     if(nums.size() == 1) {
    //         return target == nums[0] ? 0 : -1;
    //     }
    //     // 注意这里的元素可能在0位置旋转，此时相当于没有进行旋转，可以直接进行二分查找。
    //     if(nums.front() < nums.back()) {
    //         return binSearch(nums, target);
    //     }
    //     int leftIdx = 0, rightIdx = nums.size() - 1;
    //     int midIdx = (leftIdx + rightIdx) / 2;
    //     // 二分查找，找到旋转后数组中最小元素的索引
    //     while(leftIdx < rightIdx) {
    //         if(nums[midIdx] >= nums[0]) {
    //             leftIdx = midIdx + 1;
    //         }
    //         else if(nums[midIdx] <= nums[nums.size() - 1]) {
    //             rightIdx = midIdx;
    //         }
    //         midIdx = (leftIdx + rightIdx) / 2;
    //     }
    //     // 重新定位leftIdx为最小的元素，rightIdx为最大的元素
    //     leftIdx = midIdx;
    //     if(midIdx + 1 < nums.size() && nums[midIdx] > nums[midIdx + 1]) {
    //         leftIdx += 1;
    //     }
    //     rightIdx = leftIdx + nums.size() - 1;
    //     midIdx = (leftIdx + rightIdx) / 2;
    //     // 现在可以二分查找了
    //     while(leftIdx < rightIdx) {
    //         if(target < nums[midIdx % nums.size()]) {
    //             rightIdx = midIdx;
    //         }
    //         else if(target > nums[midIdx % nums.size()]) {
    //             leftIdx = midIdx + 1;
    //         }
    //         else {
    //             return (midIdx % nums.size());
    //         }
    //         midIdx = (leftIdx + rightIdx) / 2;
    //     }
    //     return nums[midIdx % nums.size()] == target ? (midIdx % nums.size()) : -1;
    // }

    // int binSearch(vector<int> &nums, int target) {
    //     int leftIdx = 0, rightIdx = nums.size() - 1, midIdx;
    //     midIdx = (leftIdx + rightIdx) / 2;
    //     while(leftIdx < rightIdx) {
    //         if(target > nums[midIdx]) {
    //             leftIdx = midIdx + 1;
    //         }
    //         else if(target < nums[midIdx]) {
    //             rightIdx = midIdx;
    //         }
    //         else {
    //             return midIdx;
    //         }
    //         midIdx = (leftIdx + rightIdx) / 2;
    //     }
    //     return nums[midIdx] == target ? midIdx : -1;
    // }

    // 将数组一分为二，其中一定有一个是有序的，另一个可能是有序，也能是部分有序。
    // 此时有序部分用二分法查找。无序部分再一分为二，其中一个一定有序，另一个可
    // 能有序，可能无序。就这样循环. 
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int leftIdx = 0, rightIdx = nums.size() - 1, midIdx;
        midIdx = (leftIdx + rightIdx) / 2;
        while(leftIdx < rightIdx) {
            if(nums[midIdx] == target) {
                return midIdx;
            }
            if(nums[leftIdx] == target) {
                return leftIdx;
            }
            if(nums[rightIdx] == target) {
                return rightIdx;
            }
            // 左侧有序
            if(nums[midIdx] > nums[leftIdx]) {
                if(target < nums[midIdx] && target > nums[leftIdx]) {
                    rightIdx = midIdx;
                }
                else {
                    leftIdx = midIdx + 1;
                }
            }
            // 右侧有序
            else {
                if(target > nums[midIdx] && target < nums[rightIdx]) {
                    leftIdx = midIdx + 1;
                }
                else {
                    rightIdx = midIdx;
                }
            }
            midIdx = (leftIdx + rightIdx) / 2;
        }   
        return nums[leftIdx] == target ? leftIdx : -1;
    }
};
// @lc code=end

