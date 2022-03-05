/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     vector<int> help(nums1.size() + nums2.size(), 0);
    //     /* merge两个数组 */
    //     int i = 0, j = 0, k = 0;
    //     while(i < nums1.size() && j < nums2.size()) {
    //         if(nums1[i] < nums2[j]) {
    //             help[k] = nums1[i++];
    //         }
    //         else {
    //             help[k] = nums2[j++];
    //         }
    //         ++k;
    //     }
    //     while(i < nums1.size()) {
    //         help[k++] = nums1[i++];
    //     }
    //     while(j < nums2.size()) {
    //         help[k++] = nums2[j++];
    //     }
    //     double result;
    //     if(help.size() % 2 == 0) {
    //         result = double(help[help.size() / 2 - 1]) + help[help.size() / 2];
    //         result /= 2;
    //     }
    //     else {
    //         result = help[help.size() / 2];
    //     }
    //     return result;
    // }

    /* 不需要将全部的数据进行merge，只需要有一个长度为2的数组保存数据即可 */
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int i = 0, j = 0, k = 0, midLen = nums1.size() + nums2.size();
    //     midLen = midLen / 2 + 1;
    //     int help[2] = {0, 0};
    //     while(i < nums1.size() && j < nums2.size() && k < midLen) {
    //         if(nums1[i] < nums2[j]) {
    //             help[k % 2] = nums1[i++];
    //         }
    //         else {
    //             help[k % 2] = nums2[j++];
    //         }
    //         ++k;
    //     }
    //     while(i < nums1.size() && k < midLen) {
    //         help[k % 2] = nums1[i++];
    //         ++k;
    //     }
    //     while(j < nums2.size() && k < midLen) {
    //         help[k % 2] = nums2[j++];
    //         ++k;
    //     }
    //     /* 总共偶数个数据 */
    //     if((nums1.size() + nums2.size()) % 2 == 0) {
    //         return (static_cast<double>(help[0]) + help[1]) / 2;
    //     }
    //     /* 总共奇数个数据，那么最后一个填入的数据就是结果 */
    //     else {
    //         return help[(k - 1) % 2];
    //     }
    // }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *pnumArr1, *pnumArr2;
        // 始终让numArr1为较短的那一个，numArr2为较长的那一个
        if(nums1.size() < nums2.size()) {
            pnumArr1 = &nums1;
            pnumArr2 = &nums2;
        }
        else {
            pnumArr1 = &nums2;
            pnumArr2 = &nums1;
        }
        // 总元素个数为偶数时，左侧元素数量应等于右侧元素数量，总元素个数为奇数时
        // 左侧元素数量应等于右侧元素数量加一
        int totalLeft = (pnumArr1->size() + pnumArr2->size() + 1) / 2;
        int left = 0;
        int right = pnumArr1->size();
        while(left < right) {
            // 分界限位置等于分界线左侧的元素数量，所以有i + j = totalLeft
            /* 第一根分界线 */
            int i = (left + right + 1) / 2;
            /* 第二根分界线 */
            int j = totalLeft - i;
            if((*pnumArr1)[i - 1] > (*pnumArr2)[j]) {
                right = i - 1;
            }
            else {
                left = i;
            }
        }
        int first = left;
        int second = totalLeft - left;
        int firstLeft = (first - 1 < 0) ? INT_MIN : (*pnumArr1)[first - 1];
        int firstRight = (first >= pnumArr1->size()) ? INT_MAX : (*pnumArr1)[first];
        int secondLeft = (second - 1 < 0) ? INT_MIN : (*pnumArr2)[second - 1];
        int secondRight = (second >= pnumArr2->size()) ? INT_MAX : (*pnumArr2)[second];
        /* 总元素奇数个 */
        if((pnumArr1->size() + pnumArr2->size()) % 2 == 1) {
            return firstLeft > secondLeft ? firstLeft : secondLeft;
        }
        /* 总元素偶数个 */
        else {
            return static_cast<double>(max(firstLeft, secondLeft) + min(firstRight, secondRight)) / 2;
        }
    }
};
// @lc code=end

