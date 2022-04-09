/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    // bool isHappy(int n) {
    //     set<int> lockedNum;
    //     while(n != 0) {
    //         lockedNum.insert(n);
    //         int nCopy = n;
    //         n = 0;
    //         while(nCopy) {
    //             int num = nCopy % 10;
    //             n += pow(num, 2);
    //             nCopy /= 10;
    //         }
    //         if(lockedNum.count(n) != 0) {
    //             break;
    //         }
    //     }
    //     return n == 1 ? true : false;
    // }

    // 通过反复调用 getNext(n) 得到的链是一个隐式的链表。
    // 隐式意味着我们没有实际的链表节点和指针，但数据仍然
    // 形成链表结构。起始数字是链表的头 “节点”，链中的所有
    // 其他数字都是节点。next 指针是通过调用 getNext(n) 函数获得。
    bool isHappy(int n) {
        int slow = getNext(n);
        int fast = getNext(getNext(n));
        while(slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return slow == 1 ? true : false;
    }

    int getNext(int n) {
        int nCopy = n;
        n = 0;
        while(nCopy) {
            n += pow(nCopy % 10, 2);
            nCopy /= 10;
        }
        return n;
    }
};
// @lc code=end

