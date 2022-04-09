/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    MyStack() : isFirstEmpty(true) {

    }
    
    void push(int x) {
        if(isFirstEmpty) {
            que1.push(x);
            while(!que2.empty()) {
                que1.push(que2.front());
                que2.pop();
            }
        }
        else {
            que2.push(x);
            while(!que1.empty()) {
                que2.push(que1.front());
                que1.pop();
            }
        }
        isFirstEmpty = !isFirstEmpty;
    }
    
    int pop() {
        int ans = 0;
        if(que1.empty()) {
            ans = que2.front();
            que2.pop();
        }
        else {
            ans = que1.front();
            que1.pop();
        }
        return ans;
    }
    
    int top() {
        return isFirstEmpty ? que2.front() : que1.front();
    }
    
    bool empty() {
        return que1.empty() && que2.empty();
    }
private:
    queue<int> que1;
    queue<int> que2;
    bool isFirstEmpty;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

