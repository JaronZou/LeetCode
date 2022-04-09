/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        inStack.push(x);
    }
    
    int pop() {
        if(outStack.empty()) {
            transfer();
        }
        int num = outStack.top();
        outStack.pop();
        return num;
    }
    
    int peek() {
        if(outStack.empty()) {
            transfer();
        }
        return outStack.top();
    }
    
    bool empty() {
        return outStack.empty() && inStack.empty();
    }
private:
    void transfer() {
        while(!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }
private:
    stack<int> outStack;
    stack<int> inStack;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

