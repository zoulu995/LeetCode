/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    stack<int> minstk;
    MinStack() {
    }
    
    void push(int x) {
        stk.push(x);
        if (minstk.empty()) minstk.push(x);
        else
            minstk.push(min(minstk.top(), x));
    }
    
    void pop() {
        if (stk.size()) {
            stk.pop();
            minstk.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minstk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

