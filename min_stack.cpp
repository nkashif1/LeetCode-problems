#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> minStack; 
public:
    MinStack() {
        // nothing to push here
    }
    
    void push(int val) {
        st.push(val);
        if (minStack.empty()) {
            minStack.push(val); // first element becomes min
        } else {
            minStack.push(min(val, minStack.top())); // track current min
        }
    }
    
    void pop() {
        st.pop();
        minStack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
