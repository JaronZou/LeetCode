/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
// class MinStack {
// public:
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         num_stack.push(val);
//         int min = val;
//         if(!min_stack.empty()) {
//             min = min_stack.top() < min ? min_stack.top() : min;
//         }
//         min_stack.push(min);
//     }
    
//     void pop() {
//         num_stack.pop();
//         min_stack.pop();
//     }
    
//     int top() {
//         return num_stack.top();
//     }
    
//     int getMin() {
//         return min_stack.top();
//     }
// private:
//     // 辅助栈，保存当前栈num_stack中的最小值
//     stack<int> min_stack;
//     stack<int> num_stack;
// };

// 插值法
// 使用 long long 防止溢出
class MinStack {
public:
    MinStack() : curMin(INT_MIN) {

    }
    
    void push(int val) {
        if(!nums.empty()) {
            long long sub = val - curMin;
            nums.push(sub);
            if(sub < 0) {
                curMin += sub;
            }
        }
        else {
            nums.push(0);
            curMin = val;
        }
    }
    
    void pop() {
        if(nums.top() < 0) {
            curMin -= nums.top();
        }
        nums.pop();
    }
    
    int top() {
        return nums.top() < 0 ? curMin : curMin + nums.top();
    }
    
    int getMin() {
        return curMin;
    }

private:
    stack<long long> nums;
    long long curMin;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

